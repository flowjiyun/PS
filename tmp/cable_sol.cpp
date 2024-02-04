#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int MAX_DEVICE = 10001;

struct Node
{
  int parentID;
  int level;
  vector<int> childs;
};

int id;
Node tree[MAX_DEVICE];
unordered_map<int, int> idHashMap;

void init(int mDevice)
{
  for (int i = 0; i < id; ++id)
  {
    tree[i].parentID = 0;
    tree[i].level = 0;
    tree[i].childs.clear();
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
  idHashMap[mNewDevice] = id;

  // 무방향 그래프
  // 부모 관련 정보 업데이트
  // - 자식 연결
  // 자식 관련 정보 업데이트
  // - 부모 아이디 저장
  // - 자식에 부모 추가 (무방향 그래프)
  // - 레벨 증가 시키기 (부모 + 1)
  tree[oldID].childs.push_back(newID);
  tree[newID].parentID = oldID;
  tree[newID].level = tree[oldID].level + 1;
  tree[newID].childs.push_back(oldID);
  return;
}

static int getLatency(int parentID, int curID, int toID, int sum)
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

  return getLatency(fromID, fromID, toID, 0);
}

// curID 부터 시작해서 연결되는 트리 경로 중 가장 큰 가중치를 가지는 경로를 얻어내는 함수
static int getMaxLatency(int parentID, int curID)
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
  root = idHashMap[mDevice];
  int adjLen = tree[root].size();
  if (adjLen == 1)
  {
    return getMaxLatency(root, root);
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
    return ret[0] + ret[1];
  }
}
