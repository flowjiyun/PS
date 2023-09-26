#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

int n, m, r;

vector<int> info[200001];
int visited[100001] = {0, };
int seq = 1;
void dfs(int startNode) {
  if (visited[startNode] != 0) {
    return;
  }
  visited[startNode] = seq++;
  for (int i = 0; i < info[startNode].size(); ++i) {
      dfs(info[startNode][i]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m >> r;
  for (int i = 0; i < m; ++i) {
    int first, second;
    cin >> first >> second;
    info[first].push_back(second);
    info[second].push_back(first);
  }
  for (int i = 1; i <= n; ++i) {
    sort(info[i].begin(), info[i].end());
  }

  // for (int i  = 0; i < m; ++i) {
  //   cout << info[i].first << info[i].second << '\n';
  // }
  dfs(r);
  for (int i = 1; i <= n; ++i) {
    cout << visited[i] << '\n';
  }
  return 0;
}