#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct NextPos {
  NextPos(int dis, int i, int j) : dis_(dis), i_(i), j_(j) {};
  int dis_;
  int i_;
  int j_;
};

bool isSharkCanEat(int sharkSize, int n, vector<vector<int>> &space) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (space[i][j] != 0 && space[i][j] < sharkSize) {
        ++cnt;
      }
    }
  } 
  if (cnt) {
    return true;
  }
  return false;
}

bool comp(NextPos &a, NextPos &b) {
    if (a.dis_ == b.dis_) {
      if (a.i_ == b.i_) {
        return a.j_ < b.j_;
      } else {
        return a.i_ < b.i_;
      }
    } else {
      return a.dis_ < b.dis_;
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> space(n, vector<int>(n, 0));
  pair<int, int> sharkPos;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> space[i][j];
      if (space[i][j] == 9) {
        sharkPos = {i, j};
      }
    }
  }
  // cout << sharkPos.first << sharkPos.second;
  int sharkSize = 2;
  int curEaten = 0;
  int time = 0;
  while(1) {
    vector<vector<int>> visited(n, vector<int>(n, -1));
    queue<pair<int, int>> queue;
    vector<NextPos> nextPosList;
    queue.push(sharkPos);
    visited[sharkPos.first][sharkPos.second] = 0;
    while (!queue.empty()) {
      auto curPos = queue.front();
      queue.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int ny = curPos.first + dy[dir];
        int nx = curPos.second + dx[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
          continue;
        }
        if (visited[ny][nx] != -1 || space[ny][nx] > sharkSize) {
          continue;
        }
        if (visited[ny][nx] == -1 && (space[ny][nx] == sharkSize || space[ny][nx] == 0)) {
          visited[ny][nx] = visited[curPos.first][curPos.second] + 1;
          queue.push({ny, nx});
        } else if (visited[ny][nx] == -1 && space[ny][nx] < sharkSize) {
          // update nextposlist
          visited[ny][nx] = visited[curPos.first][curPos.second] + 1;
          nextPosList.push_back(NextPos(visited[ny][nx], ny, nx));
        }
      }
    }
    // for (auto row : visited) {
    //   for (auto col : row) {
    //     cout << col << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << "-------------" << '\n';
    // sort nextposlist
    if (nextPosList.size() > 0) {
      sort(nextPosList.begin(), nextPosList.end(), comp);
      // for (auto val : nextPosList) {
      //   cout << val.dis_ << ' '<< val.i_ << ' ' << val.j_ << '\n';
      // }
      auto nextPos = nextPosList[0];
      // cout << "nextpos :" << nextPos.i_ << ' ' << nextPos.j_ << " dis: " << nextPos.dis_ << '\n';
      ++curEaten;
      if (curEaten == sharkSize) {
        ++sharkSize;
        curEaten = 0;
      }
      space[sharkPos.first][sharkPos.second] = 0;
      space[nextPos.i_][nextPos.j_] = 9;
      time += nextPos.dis_;
      sharkPos = {nextPos.i_, nextPos.j_};
    } else {
      break;
    }
  }
  cout << time;
  return 0;
}