#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, k;
int visited[100005];
int cnt[100005];
int da[4] = {2, 1, 1};
int db[4] = {0, 1, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  if (n == k) {
    cout << '0' << '\n';
    cout << '1' << '\n';
    return 0;
  }

  queue<int> queue;
  queue.push(n);
  cnt[n] = 1;
  while (!queue.empty()) {
    auto cur = queue.front();
    queue.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur * da[dir] + db[dir];
      if (nx < 0 || nx >= 100000) {
        continue;
      }
      if (!visited[nx]) {
        queue.push(nx);
        visited[nx] = visited[cur] + 1;
        cnt[nx] += cnt[cur];
      } else if (visited[nx] == visited[cur] + 1) {
        cnt[nx] += cnt[cur];
      }
    }
  }
  cout << visited[k] << '\n';
  cout << cnt[k] << '\n';
  return 0;
}