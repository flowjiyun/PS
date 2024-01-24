#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
const int MAX_VAL = numeric_limits<int>::max();

int map[101][101];

void getMinDist(vector<vector<int>> &d) {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      minHeap;
  int n = d.size();
  d[0][0] = 0;
  minHeap.push({0, {0, 0}});

  while (!minHeap.empty()) {
    int curDist = minHeap.top().first;
    int curRow = minHeap.top().second.first;
    int curCol = minHeap.top().second.second;
    minHeap.pop();

    if (curDist > d[curRow][curCol]) {
      continue;
    }

    for (int dir = 0; dir < 4; ++dir) {
      int nRow = curRow + dy[dir];
      int nCol = curCol + dx[dir];
      if (nRow < 0 || nCol < 0 || nRow >= n || nCol >= n) {
        continue;
      }
      int weight = map[nRow][nCol];
      int dist = curDist + weight;

      if (d[nRow][nCol] > dist) {
        d[nRow][nCol] = dist;
        minHeap.push({dist, {nRow, nCol}});
      }
    }
  }
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test_case;
  int T;
  // freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); ++j) {
        map[i][j] = s[j] - '0';
      }
    }
    vector<vector<int>> d = vector<vector<int>>(n, vector<int>(n, MAX_VAL));
    getMinDist(d);
    cout << "#" << test_case << " " << d[n - 1][n - 1] << "\n";
  }
  return 0;
}