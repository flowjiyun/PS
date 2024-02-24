#include <unordered_map>
#include <algorithm>
#include <cstring>

struct Node
{
  int id;
  int parent;
  int subTreeCnt;
  int childrenCnt;
  int val;
};

Node nodePool[18000];
bool isRemoved[18000];

int idx = 0;
int n;
std::unordered_map<int, int> idMap;

int MakeNode(int id, int val)
{
  Node &newNode = nodePool[idx];
  ++idx;
  newNode.id = id;
  newNode.parent = -1;
  newNode.subTreeCnt = 0;
  newNode.val = val;
  newNode.childrenCnt = 0;
  return idx - 1;
}

void init(int N, int mId[], int mNum[])
{
  idx = 0;
  n = N;
  memset(nodePool, 0, sizeof(nodePool));
  memset(isRemoved, 0, sizeof(isRemoved));
  for (int i = 0; i < N; ++i)
  {
    idMap[mId[i]] = idx; // id mapping
    MakeNode(mId[i], mNum[i]);
  }

  return;
}

void UpdateSubInfo(int nodeIndex, int delta, int val = 0)
{
  while (nodeIndex != -1)
  {
    nodePool[nodeIndex].subTreeCnt += delta;
    nodePool[nodeIndex].val += val;
    nodeIndex = nodePool[nodeIndex].parent;
  }
}

int add(int mId, int mNum, int mParent)
{
  // mParent
  int parentNodeIndex = idMap[mParent];
  // 자식 노드의 갯수가 3 이상이면 추가 불가
  if (nodePool[parentNodeIndex].childrenCnt == 3)
  {
    return -1;
  }
  // 부모의 자식노드 개수 추가
  ++nodePool[parentNodeIndex].childrenCnt;

  idMap[mId] = idx;
  int newNodeIndex = MakeNode(mId, mNum);
  // subTreeNode 갯수 업데이트
  // val 업데이트
  UpdateSubInfo(parentNodeIndex, 1, mNum);
  // 새로운 노드를 부모 노드에 연결
  nodePool[newNodeIndex].parent = parentNodeIndex;

  return nodePool[parentNodeIndex].val;
}

int remove(int mId)
{
  // 없는 노드 삭제할때
  if (idMap.count(mId) == 0)
  {
    return -1;
  }
  // 현재 노드부터 최상단 노드까지 올라가면서 한번이라도 삭제 되었으면 삭제 못함
  int targetNodeIndex = idMap[mId];
  int nodeIndex = targetNodeIndex;
  while (nodeIndex != -1)
  {
    if (isRemoved[nodeIndex])
    {
      return -1;
    }
    nodeIndex = nodePool[nodeIndex].parent;
  }
  // 정상 삭제 가능할때
  int parentNodeIndex = nodePool[targetNodeIndex].parent;
  --nodePool[parentNodeIndex].childrenCnt;

  int delta = -(nodePool[targetNodeIndex].subTreeCnt + 1);
  int val = nodePool[targetNodeIndex].val;
  UpdateSubInfo(parentNodeIndex, delta, -val);
  isRemoved[targetNodeIndex] = true;
  return val;
}

// parametric search
int distribute(int K)
{
  int maxVal = 0;
  for (int i = 0; i < n; ++i)
  {
    maxVal = std::max(maxVal, nodePool[i].val);
  }
  int left = 0;
  int right = std::min(maxVal, K);
  while (left < right)
  {
    int mid = (left + right + 1) / 2;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
      cnt += std::min(mid, nodePool[i].val);
    }
    if (cnt <= K)
    {
      left = mid;
    }
    else
    {
      right = mid - 1;
    }
  }
  return left;
}