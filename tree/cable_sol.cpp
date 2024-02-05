#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int MAX_DEVICE = 10005;

struct Node
{
  int parentID;
  int level;
  int weight;
};

int root, id;
Node nodeInfo[MAX_DEVICE];
vector<pair<int, int>> tree[MAX_DEVICE];
unordered_map<int, int> idHashMap;

void init(int mDevice)
{
  for (int i = 0; i <= id; ++i)
  {
    nodeInfo[i].parentID = 0;
    nodeInfo[i].level = 0;
    nodeInfo[i].weight = 0;
    tree[i].clear();
  }
  id = 0;
  idHashMap.clear();
  idHashMap[mDevice] = id;
  return;
}

void connect(int mOldDevice, int mNewDevice, int mLatency)
{
  // id mapping
  int oldID = idHashMap[mOldDevice];
  int newID = ++id;
  idHashMap[mNewDevice] = newID;

  // 무방향 그래프
  // 부모 관련 정보 업데이트
  // - 자식 연결
  // 자식 관련 정보 업데이트
  // - 부모 아이디 저장
  // - 자식에 부모 추가 (무방향 그래프)
  // - 레벨 증가 시키기 (부모 + 1)
  tree[oldID].push_back({newID, mLatency});
  tree[newID].push_back({oldID, mLatency});
  nodeInfo[newID].parentID = oldID;
  nodeInfo[newID].weight = mLatency;
  nodeInfo[newID].level = nodeInfo[oldID].level + 1;
  return;
}

int getLatency(int parentID, int curID, int toID, int sum)
{
  if (curID == toID)
  {
    return sum;
  }
  for (const auto &neighbor : tree[curID])
  {
    int neighborID = neighbor.first;
    int weight = neighbor.second;
    if (neighborID == parentID)
    {
      continue;
    }
    int ret = getLatency(curID, neighborID, toID, sum + weight);
    if (ret)
    {
      return ret;
    }
  }
  return 0;
}

int measure(int mDevice1, int mDevice2)
{
  int fromID = idHashMap[mDevice1];
  int toID = idHashMap[mDevice2];

  // LCA
  //  1. find large level (formID vs toID)
  //  2. adjust large level with small level
  //  3. loop while same id
  if (nodeInfo[fromID].level < nodeInfo[toID].level)
  {
    // toID를 작은 값으로 변경
    swap(fromID, toID);
  }
  int delta = nodeInfo[fromID].level - nodeInfo[toID].level;
  int ret = 0;
  while (delta)
  {
    ret += nodeInfo[fromID].weight;
    fromID = nodeInfo[fromID].parentID;
    --delta;
  }
  while (fromID != toID)
  {
    ret += nodeInfo[fromID].weight;
    ret += nodeInfo[toID].weight;
    fromID = nodeInfo[fromID].parentID;
    toID = nodeInfo[toID].parentID;
  }
  return ret;
}

// curID 부터 시작해서 연결되는 트리 경로 중 가장 큰 가중치를 가지는 경로를 얻어내는 함수
int getMaxLatency(int parentID, int curID)
{
  int maxVal = 0;
  for (const auto &neighbor : tree[curID])
  {
    int neighborID = neighbor.first;
    int weight = neighbor.second;
    if (neighborID == parentID)
    {
      continue;
    }
    int ret = getMaxLatency(curID, neighborID) + weight;
    // 최대 값 갱신
    maxVal = max(maxVal, ret);
  }
  // 자식 노드 없으면 0 반환
  return maxVal;
}
int test(int mDevice)
{
  vector<int> ret;
  int root = idHashMap[mDevice];
  int adjLen = tree[root].size();
  int ans;
  if (adjLen == 1)
  {
    ans = getMaxLatency(root, root);
    return ans;
  }
  else
  {
    for (const auto &neighbor : tree[root])
    {
      int curVal = 0;
      int neighborID = neighbor.first;
      int weight = neighbor.second;
      curVal = getMaxLatency(root, neighborID) + weight;
      ret.push_back(curVal);
    }
    sort(ret.rbegin(), ret.rend());
    ans = ret[0] + ret[1];
    return ans;
  }
}
