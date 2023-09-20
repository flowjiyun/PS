#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int comb[10];
vector<vector<int>> virusComb;
void getCombination(int n, int r, int index, int cur) {
  if (index == r) {
    vector<int> val;
    for (int i = 0; i < r; ++i) {
      val.push_back(comb[i]);
    }
    virusComb.push_back(val);
    return;
  }
  for (int i = cur; i < n; ++i) {
    comb[index] = i;
    getCombination(n, r, index + 1, i + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> space(n, vector<int>(n, 0));
  vector<pair<int, int>> virus;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> space[i][j];
      if (space[i][j] == 2) {
        virus.push_back({i, j});
      }
    }
  }
  int virusListSize = virus.size();
  getCombination(virusListSize, m, 0, 0);
  // for (auto list : virusComb) {
  //   for (auto val : list) {
  //     cout << val << ' ';
  //   }
  //   cout << '\n';
  // }
  vector<int> ansList;
  int okcnt = 0;
  for (auto list : virusComb) {
    int maxVal = numeric_limits<int>::min();
    vector<vector<int>> visited(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (space[i][j] == 1) {
          visited[i][j] = -2;
        }
      }
    }
    queue<pair<int, int>> queue;
    for (auto val : list) {
      queue.push(virus[val]);
      visited[virus[val].first][virus[val].second] = 0;
    }
    while (!queue.empty()) {
      auto cur = queue.front();
      queue.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int ny = cur.first + dy[dir];
        int nx = cur.second + dx[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
          continue;
        }
        if (visited[ny][nx] != -1 || space[ny][nx] == 1) {
          continue;
        }
        visited[ny][nx] = visited[cur.first][cur.second] + 1;
        queue.push({ny, nx});
      }
    }
    // for (auto val : list) {
    //   cout << val << ' ';
    // }
    // cout << '\n';
    // for (auto y : visited) {
    //   for (auto x : y) {
    //     cout << x << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << "================" << '\n';
    int cnt = 0;
    for (auto row : visited) {
      for (auto col : row) {
        if (col == -1) {
          ++cnt;
        }
        maxVal = max(maxVal, col);
      }
    }
    if (cnt == 0) {
      ++okcnt;
      ansList.push_back(maxVal);
    }
  }
  if (okcnt == 0) {
    cout << "-1";
    return 0;
  }
  sort(ansList.begin(), ansList.end());
  cout << ansList[0];
  return 0;
}
