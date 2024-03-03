#include <limits>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

std::unordered_map<int, int> idHash;

std::vector<std::pair<int, int>> graphInfo[600];
std::vector<std::pair<int, int>> reverseGraphInfo[600];

int nodeCnt;
int init(int N, int sCity[], int eCity[], int mCost[]) {
  idHash.clear();

  for (int i = 0; i < 600; ++i) {
    graphInfo[i].clear();
    reverseGraphInfo[i].clear();
  }

  int index = 0;
  for (int i = 0; i < N; ++i) {
    if (idHash.count(sCity[i]) == 0) {
      idHash.insert({sCity[i], index++});
    }
  }

  for (int i = 0; i < N; ++i) {
    int startIndex = idHash[sCity[i]];
    int endIndex = idHash[eCity[i]];
    int cost = mCost[i];

    graphInfo[startIndex].push_back({endIndex, cost});
    reverseGraphInfo[endIndex].push_back({startIndex, cost});
  }
  nodeCnt = index;
  return index;
}

void add(int sCity, int eCity, int mCost) {
  int startIndex = idHash[sCity];
  int endIndex = idHash[eCity];

  graphInfo[startIndex].push_back({endIndex, mCost});
  reverseGraphInfo[endIndex].push_back({startIndex, mCost});
  return;
}

int getMinDistSum(std::vector<std::pair<int, int>> *graphInfo, int startIndex) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      minHeap;
  std::vector<int> dist(nodeCnt, std::numeric_limits<int>::max());
  minHeap.push({0, startIndex});
  dist[startIndex] = 0;

  while (!minHeap.empty()) {
    int curDist = minHeap.top().first;
    int curIndex = minHeap.top().second;
    minHeap.pop();

    if (curDist > dist[curIndex]) {
      continue;
    }

    for (auto nextNode : graphInfo[curIndex]) {
      int nextIndex = nextNode.first;
      int weight = curDist + nextNode.second;

      if (weight < dist[nextIndex]) {
        dist[nextIndex] = weight;
        minHeap.push({weight, nextIndex});
      }
    }
  }
  int answer = 0;
  for (int i = 0; i < nodeCnt; ++i) {
    answer += dist[i];
  }
  return answer;
}

int cost(int mHub) {
  int startIndex = idHash[mHub];

  return getMinDistSum(graphInfo, startIndex) +
         getMinDistSum(reverseGraphInfo, startIndex);
}