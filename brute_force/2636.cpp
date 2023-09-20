#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <limits>

// bfs outside of cheese & get 

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int getCheeseCnt(int r, int c, vector<vector<int>> &cheese) {
  int cheeseCnt = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (cheese[i][j] == 1) {
        ++cheeseCnt;
      }
    }
  }
  return cheeseCnt;
}

bool isNoCheese(int r, int c, vector<vector<int>> &cheese) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (cheese[i][j] == 1) {
        return false;
      }
    }
  }
  return true;

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c;
  cin >> r >> c;

  vector<vector<int>> cheese(r, vector<int>(c, 0));
  vector<int> cheeseCnt;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> cheese[i][j];
    }
  }
  int time = 0;
  cheeseCnt.push_back(getCheeseCnt(r, c, cheese));
  while (!isNoCheese(r, c, cheese)) {
    vector<pair<int, int>> changedPos;
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<pair<int, int>> queue;
    queue.push({0, 0});
    visited[0][0] = true;
    while (!queue.empty()) {
      auto curPos = queue.front();
      queue.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int ny = curPos.first + dy[dir];
        int nx = curPos.second + dx[dir];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) {
          continue;
        }
        if (visited[ny][nx] || cheese[ny][nx] == 1) {
          if (cheese[ny][nx] == 1) {
            changedPos.push_back({ny, nx});
          }
          continue;
        }
        visited[ny][nx] = true;
        queue.push({ny, nx});
      }
    }
    for (auto pos : changedPos) {
      cheese[pos.first][pos.second] = 0;
    }
    // cout << getCheeseCnt(r, c, cheese) << '\n';
    cheeseCnt.push_back(getCheeseCnt(r, c, cheese));
    ++time;
  }
  cheeseCnt.pop_back();
  cout << time << '\n';
  cout << cheeseCnt.back();
  return 0;
}