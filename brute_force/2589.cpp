#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <utility>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c;
  cin >> r >> c;
  vector<string> space(r);
  vector<pair<int, int>> lPosition;
  for (int i = 0; i < r; ++i) {
    cin >> space[i];
    for (int j = 0; j < static_cast<int>(space[i].size()); ++j) {
      if (space[i][j] == 'L') {
        lPosition.push_back({i, j});
      }
    }
  }

  queue<pair<int, int>> queue;
  int maxDistance = 0;
  for (auto startPosition : lPosition) {
    vector<vector<int>> visited(r, vector<int>(c, -1));
    queue.push({startPosition.first, startPosition.second});
    visited[startPosition.first][startPosition.second] = 0;
    while (!queue.empty()) {
      auto cur = queue.front();
      queue.pop();
      for (int k = 0; k < 4; ++k) {
        int nx = cur.first + dx[k];
        int ny = cur.second + dy[k];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
          continue;
        }
        if (visited[nx][ny] != -1 || space[nx][ny] == 'W') {
          continue;
        }
        visited[nx][ny] = visited[cur.first][cur.second] + 1;
        maxDistance = max(maxDistance, visited[nx][ny]);
        queue.push({nx, ny});
      }
    }
  }
  cout << maxDistance;
  return 0;
}