#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int n, m;
string input;
vector<string > map;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> input;
    map.push_back(input);
  }
  vector<vector<int> > visit(n, vector<int>(m, 0));
  queue<pair<int, int> > check_queue;
  check_queue.push({0,0});
  visit[0][0] = 1;
  while (!check_queue.empty()) {
    pair<int, int> pos = check_queue.front();
    check_queue.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = pos.first + dy[i];
      int nx = pos.second + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m)
        continue;
      if (visit[ny][nx] != 0 || map[ny][nx] == '0')
        continue;
      visit[ny][nx] = visit[pos.first][pos.second] + 1;
      check_queue.push({ny, nx});
    }
  }
  cout << visit[n - 1][m - 1];
  return (0);
}