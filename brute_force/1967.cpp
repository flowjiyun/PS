#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> tree[10001];
bool visited[10001] = {false};
int sum = 0;
int lastNode = 0;
void dfs(int curNode, int distance) {
  if (visited[curNode]) {
    return;
  }
  visited[curNode] = true;
  if (sum < distance) {
    sum = distance;
    lastNode = curNode;
  }
  for (int i = 0; i < tree[curNode].size(); ++i) {
    int nextNode = tree[curNode][i].first;
    int val = tree[curNode][i].second;
    dfs(nextNode, distance + val);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int first, second, third;
    cin >> first >> second >> third;
    tree[first].push_back({second, third});
    tree[second].push_back({first, third});
  }

  dfs(1, 0);
  sum = 0;
  memset(visited, false, sizeof(visited));
  dfs(lastNode, 0);
  cout << sum;
  return 0;
}
