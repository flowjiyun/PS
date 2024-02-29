#include <algorithm>
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
    int n, m;
    int c1, c2;
    cin >> n >> m;
    cin >> c1 >> c2;

    vector<int> cowPos(n);
    for (int i = 0; i < n; ++i) {
      cin >> cowPos[i];
    }
    sort(cowPos.begin(), cowPos.end());
    int minVal = numeric_limits<int>::max();
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      int val;
      cin >> val;
      int index;

      if (val < cowPos[0]) {
        index = 0;
      } else if (val > cowPos[n - 1]) {
        index = n - 1;
      } else {
        index = lower_bound(cowPos.begin(), cowPos.end(), val) - cowPos.begin();
      }
      int dist = abs(cowPos[index] - val);
      if (minVal > dist) {
        minVal = dist;
        cnt = 1;
      } else if (minVal == dist) {
        cnt++;
      }

      // 직선거리가 아닐때 (동일 z 좌표가 아닐때 앞으 값도 비교해야됨)
      if (1 <= index && cowPos[index] != val) {
        int prevDist = abs(cowPos[index - 1] - val);

        if (minVal > prevDist) {
          minVal = prevDist;
          cnt = 1;
        } else if (minVal == prevDist) {
          cnt++;
        }
      }
    }
    cout << "#" << test_case << " " << minVal + abs(c1 - c2) << " " << cnt
         << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}