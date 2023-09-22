#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;
// west, north, east, south
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
const int dir[4] = {1, 2, 4, 8};

int n, m;
int space[51][51];
int visited[51][51];

vector<int> getOpendir(int val) {
  vector<int> ret;
  for (int i = 0; i < 4; ++i) {
    if ((val & dir[i]) == 0) {
      ret.push_back(i);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      cin >> space[y][x];
    }
  }

  memset(visited, 0, sizeof(visited));
  int curMax = numeric_limits<int>::min();
  queue<pair<int, int>> queue;
  int roomCnt = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (!visited[y][x]) {
        queue.push({y, x});
        visited[y][x] = 1;
        ++roomCnt;
      }
      int curCnt = 1;
      while (!queue.empty()) {
        auto curPos = queue.front();
        queue.pop();
        int curY = curPos.first;
        int curX = curPos.second;
        int curValue = space[curY][curX];
        vector<int> openDir = getOpendir(curValue);
        if (openDir.size() != 0) {
          for (auto dir : openDir) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
              continue;
            }
            if (visited[ny][nx] == 1) {
              continue;
            }
            visited[ny][nx] = 1;
            queue.push({ny, nx});
            ++curCnt;
          }
        }
      }
      curMax = max(curMax, curCnt);
    }
  }
  cout << roomCnt << '\n';
  cout << curMax << '\n';
  curMax = numeric_limits<int>::min();
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      for (int k = 0; k < 4; ++k) {
        int val = space[y][x] - dir[k];
        if (val < 0) {
          continue;
        }
        space[y][x] -= dir[k];
        // do logic 
        memset(visited, 0, sizeof(visited));
        if (!visited[y][x]) {
          queue.push({y, x});
          visited[y][x] = 1;
        }
        int curCnt = 1;
        while (!queue.empty()) {
          auto curPos = queue.front();
          queue.pop();
          int curY = curPos.first;
          int curX = curPos.second;
          int curValue = space[curY][curX];
          vector<int> openDir = getOpendir(curValue);
          if (openDir.size() != 0) {
            for (auto dir : openDir) {
              int ny = curY + dy[dir];
              int nx = curX + dx[dir];
              if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
              }
              if (visited[ny][nx] == 1) {
                continue;
              }
              visited[ny][nx] = 1;
              queue.push({ny, nx});
              ++curCnt;
            }
          }
        }
        curMax = max(curMax, curCnt);
        space[y][x] += dir[k];
      }
    }
  }
  cout << curMax << '\n';
  return 0;
}