#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> chains(n);
  for (int i = 0; i < n; ++i) {
    cin >> chains[i];
  }
  sort(chains.begin(), chains.end());
  int ans = 0;
  int start = 0;
  int end = chains.size() - 1;
  while (end > start) {
    --chains[start];
    if (chains[start] == 0) {
      ++start;
    }
    --end;
    ++ans;
  }
  cout << ans;
  return 0;
}