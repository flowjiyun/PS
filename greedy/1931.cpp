#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<unsigned int, unsigned int> &a, pair<unsigned int, unsigned int> &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<unsigned int, unsigned int>> confs(n);
  for (int i = 0; i < n; ++i) {
    cin >> confs[i].first >> confs[i].second;
  }
  sort(confs.begin(), confs.end(), compare);
  // for (auto val : confs) {
  //   cout << val.first << ' ' << val.second << '\n';
  // }
  int cnt = 0;
  unsigned int curStartTime = 0;
  unsigned int curEndTime = 0;
  for (int i = 0; i < n; ++i) {
    curStartTime = confs[i].first;
    if (curStartTime >= curEndTime) {
      cnt++;
      curEndTime = confs[i].second;
    }
  }
  cout << cnt;
  return 0;
}