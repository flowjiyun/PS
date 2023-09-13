#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
bool compare(pair<ll, ll> &a, pair<ll, ll> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<ll, ll>> problems(n);
  for (int i = 0; i < n; ++i) {
    cin >> problems[i].first >> problems[i].second;
  }
  sort(problems.begin(), problems.end(), compare);

  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (int i = 0; i < n; ++i) {
    ll curDeadLine = problems[i].first;
    minHeap.push(problems[i].second);
    while (minHeap.size() > curDeadLine) {
      minHeap.pop();
    }
  }
  ll ans = 0;
  while (!minHeap.empty()) {
    ans += minHeap.top();
    minHeap.pop();
  }
  cout << ans;
  return 0;
}