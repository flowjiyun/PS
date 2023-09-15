#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<pair<ll, ll> > jewelry(n);
  vector<ll> bags(k);

  for (int i = 0; i < n; ++i) {
    cin >> jewelry[i].first >> jewelry[i].second;
  }
  for (int i = 0; i < k; ++i) {
    cin >> bags[i];
  }

  sort(jewelry.begin(), jewelry.end());
  sort(bags.begin(), bags.end());

  // start with small bag && light jewly
  priority_queue<ll, vector<ll> > maxHeap;
  ll ans = 0;
  int j = 0;
  for (int i = 0; i < k; ++i) {
    // cout << "jewelry weight : " << jewelry[j].first << " bags weight : " << bags[i] << '\n';
    while (j < n && jewelry[j].first <= bags[i]) {
      // cout << "value: " << jewelry[j].second << '\n';
      maxHeap.push(jewelry[j].second);
      ++j;
    }
    if (maxHeap.size()) {
      ans += maxHeap.top();
      maxHeap.pop();
    }
  }
  cout << ans;
  return 0;
}