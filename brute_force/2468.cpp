#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int minHeight = 200;
  int maxHeight = 1;
  vector<vector<int>> space(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        cin >> space[i][j];
        minHeight = (minHeight > space[i][j]) ? space[i][j] : minHeight;
        maxHeight = (maxHeight < space[i][j]) ? space[i][j] : maxHeight;
      }
  }
  int maxVal = 1;
  for (int rainHeight = minHeight; rainHeight <= maxHeight; ++rainHeight) {
    vector<vector<int>> tmp = space;
    vector<vector<bool>> visitied(n, vector<bool>(n, false));
    int curVal = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (tmp[i][j] <= rainHeight) {
          tmp[i][j] = 0;
        }
      }
    }
    queue<pair<int, int>> queue;
    for (int i  = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visitied[i][j] && tmp[i][j] != 0) {
          visitied[i][j] = true;
          queue.push({i, j});
          ++curVal;
        }
        while (!queue.empty()) {
          auto cur = queue.front();
          queue.pop();
          for (int k = 0; k < 4; ++k) {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) {
              continue;
            }
            if (visitied[nx][ny] || tmp[nx][ny] == 0) {
              continue;
            }
            visitied[nx][ny] = true;
            queue.push({nx, ny});
          }
        }
      }
    }
    // cout << "rainHeight: " << rainHeight << "curVal : " << curVal << '\n';
    maxVal = max(maxVal, curVal);
  }
  cout << maxVal;
  return 0;
}