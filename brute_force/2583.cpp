#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int space[101][101];
int visited[101][101];
int n, m, k;
vector<int> ansList;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> k;
  while (k--) {
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < 2; ++i) {
      if (i == 0) {
        cin >> start.first >> start.second;
      } else {
        cin >> end.first >> end.second;
      }
    }
    for (int y = start.second; y < end.second; ++y) {
      for (int x = start.first; x < end.first; ++x) {
        space[y][x] += 1;
      }
    }
  }
  int roomCnt = 0;
  queue<pair<int, int>> queue;
  for (int y = 0; y < m; ++y) {
    for (int x = 0; x < n; ++x) {
      if (!visited[y][x] && space[y][x] == 0) {
        visited[y][x] = 1;
        queue.push({y, x});
        ++roomCnt;
        int cnt = 1;
        while (!queue.empty()) {
          auto curPos = queue.front();
          queue.pop();
          for (int dir = 0; dir < 4; ++dir) {
            int ny = curPos.first + dy[dir];
            int nx = curPos.second + dx[dir];

            if (ny < 0 || nx < 0 || ny >= m || nx >= n) {
              continue;
            } 
            if (visited[ny][nx] || space[ny][nx] != 0) {
              continue;
            }
            visited[ny][nx] = 1;
            queue.push({ny, nx});
            ++cnt; 
          }
        }
        ansList.push_back(cnt);
      }
    }
  }
  // for (int y = 0; y < m; ++y) {
  //   for (int x = 0; x < n; ++x) {
  //     cout << space[y][x] << ' ';
  //   }
  //   cout << '\n';
  // }
  sort(ansList.begin(), ansList.end());
  cout << roomCnt << '\n';
  for (auto val : ansList) {
    cout << val << ' ';
  }
  return 0;
}