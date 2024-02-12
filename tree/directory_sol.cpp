#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

#include <algorithm>
// #include <iostream>

struct Node {
  long long name;
  int subTreeCnt;
  int parent;
  int children[30];
  int childrenCnt;
};

Node nodePool[50001];
int idx = 0;

int MakeNode(long long name) {
  Node &newNode = nodePool[idx];
  ++idx;
  newNode.name = name;
  newNode.subTreeCnt = 0;
  newNode.parent = -1;
  newNode.childrenCnt = 0;

  return idx - 1;
}

int root;
void init(int n) {
  (void)n;
  idx = 0;
  root = MakeNode(0);
}

int GetNodeIndexFromPath(char path[PATH_MAXLEN + 1]) {
  int ret = root;
  for (int i = 1; path[i];) {
    int j = i;
    long long newName = 0;
    while (path[j] != '/') {
      newName <<= 5;
      newName += (path[j] - 'a' + 1);
      ++j;
    }
    int left = 0;
    int right = nodePool[ret].childrenCnt - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nodePool[nodePool[ret].children[mid]].name >= newName) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    ret = nodePool[ret].children[right];
    i = j + 1;
  }
  return ret;
}

void UpdateSubTreeCnt(int fromNodeIndex, int delta) {
  while (fromNodeIndex != -1) {
    nodePool[fromNodeIndex].subTreeCnt += delta;
    fromNodeIndex = nodePool[fromNodeIndex].parent;
  }
}

void AddNode(int *children, int &childrenCnt, int newNodeIndex) {
  children[childrenCnt] = newNodeIndex;
  ++childrenCnt;
  for (int i = childrenCnt - 2; i >= 0; --i) {
    if (nodePool[children[i]].name > nodePool[children[i + 1]].name) {
      std::swap(children[i], children[i + 1]);
    } else {
      break;
    }
  }
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
  int fromNodeIndex = GetNodeIndexFromPath(path);
  // std::cout << "root subcnt : " << fromNodeIndex << " "
  //           << nodePool[fromNodeIndex].subTreeCnt << std::endl;
  UpdateSubTreeCnt(fromNodeIndex, 1);
  long long newNodeName = 0;
  for (int i = 0; name[i]; ++i) {
    newNodeName <<= 5;
    newNodeName += (name[i] - 'a' + 1);
  }
  // std::cout << " name : " << newNodeName << std::endl;
  int newNodeIndex = MakeNode(newNodeName);
  // std::cout << "new node index  : " << newNodeIndex << std::endl;
  AddNode(nodePool[fromNodeIndex].children, nodePool[fromNodeIndex].childrenCnt,
          newNodeIndex);
  nodePool[newNodeIndex].parent = fromNodeIndex;
  // std::cout << nodePool[root].subTreeCnt << std::endl;
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
  int targetNodeIndex = GetNodeIndexFromPath(path);

  int parentNodeIndex = nodePool[targetNodeIndex].parent;
  int left = 0;
  int right = nodePool[parentNodeIndex].childrenCnt - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (nodePool[nodePool[parentNodeIndex].children[mid]].name >=
        nodePool[targetNodeIndex].name) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  for (int i = right + 1; i < nodePool[parentNodeIndex].childrenCnt; ++i) {
    nodePool[parentNodeIndex].children[i - 1] =
        nodePool[parentNodeIndex].children[i];
  }
  --nodePool[parentNodeIndex].childrenCnt;
  UpdateSubTreeCnt(parentNodeIndex,
                   -(nodePool[targetNodeIndex].subTreeCnt + 1));
  // std::cout << nodePool[root].subTreeCnt << std::endl;
}

void cmd_rm(int targetNodeIndex) {
  int parentNodeIndex = nodePool[targetNodeIndex].parent;
  int left = 0;
  int right = nodePool[parentNodeIndex].childrenCnt - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (nodePool[nodePool[parentNodeIndex].children[mid]].name >=
        nodePool[targetNodeIndex].name) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  for (int i = right + 1; i < nodePool[parentNodeIndex].childrenCnt; ++i) {
    nodePool[parentNodeIndex].children[i - 1] =
        nodePool[parentNodeIndex].children[i];
  }
  --nodePool[parentNodeIndex].childrenCnt;
  UpdateSubTreeCnt(parentNodeIndex,
                   -(nodePool[targetNodeIndex].subTreeCnt + 1));
}

int CopySubTree(int targetNodeIndex) {
  int ret = MakeNode(nodePool[targetNodeIndex].name);
  nodePool[ret].childrenCnt = 0;
  nodePool[ret].parent = -1;
  nodePool[ret].subTreeCnt = nodePool[targetNodeIndex].subTreeCnt;
  for (int i = 0; i < nodePool[targetNodeIndex].childrenCnt; ++i) {
    int sub = CopySubTree(nodePool[targetNodeIndex].children[i]);
    nodePool[ret].children[nodePool[ret].childrenCnt] = sub;
    ++nodePool[ret].childrenCnt;
    nodePool[sub].parent = ret;
  }
  return ret;
}
void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
  int srcNodeIndex = GetNodeIndexFromPath(srcPath);
  int dstNodeIndex = GetNodeIndexFromPath(dstPath);

  UpdateSubTreeCnt(dstNodeIndex, nodePool[srcNodeIndex].subTreeCnt + 1);
  int newNodeIndex = CopySubTree(srcNodeIndex);
  AddNode(nodePool[dstNodeIndex].children, nodePool[dstNodeIndex].childrenCnt,
          newNodeIndex);
  nodePool[newNodeIndex].parent = dstNodeIndex;
  // std::cout << nodePool[root].subTreeCnt << std::endl;
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
  int srcNodeIndex = GetNodeIndexFromPath(srcPath);
  int dstNodeIndex = GetNodeIndexFromPath(dstPath);

  UpdateSubTreeCnt(dstNodeIndex, nodePool[srcNodeIndex].subTreeCnt + 1);
  cmd_rm(srcNodeIndex);
  AddNode(nodePool[dstNodeIndex].children, nodePool[dstNodeIndex].childrenCnt,
          srcNodeIndex);
  nodePool[srcNodeIndex].parent = dstNodeIndex;
  // std::cout << nodePool[root].subTreeCnt << std::endl;
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
  int targetNodeIndex = GetNodeIndexFromPath(path);
  return nodePool[targetNodeIndex].subTreeCnt;
}
