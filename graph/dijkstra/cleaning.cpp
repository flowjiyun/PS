#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int MAX_NODE = 200000;

vector<pair<int, int>> graphInfo[MAX_NODE + 1];
vector<long long> dist(MAX_NODE + 1);
vector<int> prevEdgeInShortPath(MAX_NODE + 1);

void getShortestPath() {
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      minHeap;
  dist[1] = 0;
  prevEdgeInShortPath[1] = 0;
  minHeap.push({0, 1});

  while (!minHeap.empty()) {
    long long curDist = minHeap.top().first;
    int curNodeIndex = minHeap.top().second;
    minHeap.pop();

    if (curDist > dist[curNodeIndex]) {
      continue;
    }

    for (auto nextNodeInfo : graphInfo[curNodeIndex]) {
      int nextNodeIndex = nextNodeInfo.first;
      int weight = nextNodeInfo.second;
      long long nextDist = curDist + (long long)weight;

      if (nextDist <= dist[nextNodeIndex]) {
        if (nextDist == dist[nextNodeIndex]) {
          prevEdgeInShortPath[nextNodeIndex] =
              min(prevEdgeInShortPath[nextNodeIndex], weight);
        } else {
          dist[nextNodeIndex] = nextDist;
          prevEdgeInShortPath[nextNodeIndex] = weight;
          minHeap.push({nextDist, nextNodeIndex});
        }
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

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      graphInfo[i].clear();
      dist[i] = numeric_limits<long long>::max();
      prevEdgeInShortPath[i] = numeric_limits<int>::max();
    }
    for (int i = 0; i < m; ++i) {
      int s, e, w;
      cin >> s >> e >> w;
      graphInfo[s].push_back({e, w});
      graphInfo[e].push_back({s, w});
    }

    getShortestPath();

    long long answer = 0;
    for (int i = 1; i <= n; ++i) {
      answer += prevEdgeInShortPath[i];
    }
    cout << "#" << test_case << " " << answer << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}