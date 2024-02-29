#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int n;
    double e;
    cin >> n;

    vector<int> xPos(n);
    vector<int> yPos(n);
    vector<long long> weight(n, numeric_limits<long long>::max()); // index : to
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; ++i) {
      cin >> xPos[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> yPos[i];
    }
    cin >> e;
    // 프림 알고즘
    // - 임의의 시작점에서 시작 -> 0에서 시작
    // - mst에 추가된 노드는 체크 해줘야 함
    // - 주면 노드를 모두 탐색하면서 가장 가중치가 작은 노드를 mst에 추가
    // - 특정 노드에서 다른 노드들 까지의 가중치를 계산하는 과정 필요

    int curNodeId = 0;
    visited[curNodeId] = true;

    auto dist = [&](int i, int j) -> long long {
      return 1LL * (xPos[i] - xPos[j]) * (xPos[i] - xPos[j]) +
             1LL * (yPos[i] - yPos[j]) * (yPos[i] - yPos[j]);
    };
    long long ret = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (int nextNodeId = 0; nextNodeId < n; ++nextNodeId) {
        weight[nextNodeId] =
            min(weight[nextNodeId], dist(curNodeId, nextNodeId));
      }
      // 최초 비교 노드 고르기 위함
      curNodeId = -1;
      // 최소 가중치 가지는 노드 찾기 (완전 탐색)
      // - dense한 그래프에서 완전 탐색 시간 복잡도와 우선순위큐 시간복잡도가
      // 유사
      // - 구현하기 편한 완전 탐색 사용
      for (int nextNodeId = 0; nextNodeId < n; ++nextNodeId) {
        if (visited[nextNodeId] == true) {
          continue;
        }
        if (curNodeId == -1 || weight[curNodeId] > weight[nextNodeId]) {
          curNodeId = nextNodeId;
        }
      }
      ret += weight[curNodeId];
      visited[curNodeId] = true;
    }
    cout << "#" << test_case << " ";
    cout << fixed << setprecision(0) << e * ret << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}