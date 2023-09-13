#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> cows(n);
  for (int i = 0; i < n; ++i) {
    cin >> cows[i].first >> cows[i].second;
  }
  sort(cows.begin(), cows.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (ans < cows[i].first) {
      ans = cows[i].first + cows[i].second;
    } else {
      ans += cows[i].second;
    }
  }
  cout << ans;
  return 0;
}