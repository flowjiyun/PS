#include <unordered_map>

struct Node {
  int id;
  int parent;
  int subTreeCnt;
  int children[2];
  int childrenCnt;
  int val;
};

Node nodePool[1800];
bool isRemoved[18000];

int idx = 0;
std::unordered_map<int, int> idMap;

int MakeNode(int id, int val) {
  Node &newNode = nodePool[idx];
  ++idx;
  newNode.id = id;
  newNode.parent = -1;
  newNode.subTreeCnt = 0;
  newNode.val = val;
  newNode.childrenCnt = 0;
  return idx - 1;
}

void init(int N, int mId[], int mNum[]) {
  idx = 0;
  memset(isRemoved, 0, sizeof(isRemoved));
  for (int i = 0; i < N; ++i) {
    idMap[mId[i]] = idx; // id mapping
    MakeNode(mId[i], mNum[i]);
  }

  return;
}

void UpdateSubInfo(int nodeIndex, int delta, int val = 0) {
  while (nodeIndex != -1) {
    nodePool[nodeIndex].subTreeCnt += delta;
    nodePool[nodeIndex].val += val;
    nodeIndex = nodePool[nodeIndex].parent;
  }
}
void AddNode(int *children, int &childrenCnt, int id) {
  children[childrenCnt] = id;
  ++childrenCnt;
}

int add(int mId, int mNum, int mParent) {
  // mParent
  int parentNodeIndex = idMap[mParent];
  if (nodePool[parentNodeIndex].subTreeCnt == 3) {
    return -1;
  }
  idMap[mId] = idx;
  int newNodeIndex = MakeNode(mId, mNum);
  // subcnt 업데이트
  // val 업데이트
  UpdateSubInfo(parentNodeIndex, 1, mNum);
  // 새로운 노드를 부모 노드에 연결
  nodePool[newNodeIndex].parent = parentNodeIndex;

  return 0;
}

int remove(int mId) {
  int targetNodeIndex = idMap[mId];
  if (isRemoved[targetNodeIndex]) {
    return -1;
  }
  int parentNodeIndex = nodePool[targetNodeIndex].parent;
  int delta = -(nodePool[targetNodeIndex].subTreeCnt + 1);
  int val = -nodePool[targetNodeIndex].val;
  UpdateSubInfo(parentNodeIndex, delta, val);
  isRemoved[targetNodeIndex] = true;
  return val;
}

int distribute(int K) { return 0; }