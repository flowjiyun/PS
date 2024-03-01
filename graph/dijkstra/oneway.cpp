#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int MAX_NUM = 50005;
vector<pair<int, int>> graphInfo[MAX_NUM + 1];
vector<pair<int, int>> reverseGraphInfo[MAX_NUM + 1];

void getMinDist(vector<pair<int, int>> *graph, vector<int> &dist,
                int startIndex) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      minHeap;
  minHeap.push({0, startIndex});
  dist[startIndex] = 0;

  while (!minHeap.empty()) {
    int curDist = minHeap.top().first;
    int curIndex = minHeap.top().second;
    minHeap.pop();

    if (curDist > dist[curIndex]) {
      continue;
    }

    for (auto nextNode : graph[curIndex]) {
      int nextNodeIndex = nextNode.first;
      int weight = curDist + nextNode.second;

      if (dist[nextNodeIndex] > weight) {
        dist[nextNodeIndex] = weight;
        minHeap.push({weight, nextNodeIndex});
      }
    }
  }
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
      graphInfo[i].clear();
      reverseGraphInfo[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int s, e, t;
      cin >> s >> e >> t;
      graphInfo[s].push_back({e, t});
      reverseGraphInfo[e].push_back({s, t});
    }
    vector<int> dist1(MAX_NUM + 1, numeric_limits<int>::max());
    vector<int> dist2(MAX_NUM + 1, numeric_limits<int>::max());
    getMinDist(graphInfo, dist1, x);
    getMinDist(reverseGraphInfo, dist2, x);
    int minVal = numeric_limits<int>::min();
    for (int i = 1; i <= n; ++i) {
      minVal = max(minVal, dist1[i] + dist2[i]);
    }
    cout << "#" << test_case << " " << minVal << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}