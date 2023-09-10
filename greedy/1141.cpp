#include <iostream>
#include <vector>
#include <algorithm>

// 앞에서

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> words(n);
  vector<bool> check(n, true);
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
  }
  sort(words.begin(), words.end());

  for (size_t i = 0; i < words.size(); ++i) {
    for (size_t j = i + 1; j < words.size(); ++j) {
      if (words[j].substr(0, words[i].size()) == words[i]) {
        check[i] = false;
        break;
      }
    }
  }
  int ans = 0;
  for (auto i : check) {
    if (i) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
