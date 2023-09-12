#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> base(n);
  vector<int> growPerDay(n);
  for (int i = 0; i < n; ++i) {
    cin >> base[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> growPerDay[i];
  }
  vector<pair<int, int>> pairs;
  for (int i = 0; i < n; ++i) {
    pairs.push_back(make_pair(growPerDay[i], base[i]));
  }
  sort(pairs.begin(), pairs.end());
  long long ans = 0;
  for (size_t i = 0; i < pairs.size(); ++i) {
    ans += (pairs[i].first * i + pairs[i].second);
  }
  cout << ans;
  // bad solved
  // vector<int> base(n);
  // vector<int> add(n);
  // vector<pair<int, int>> origin;
  // int ans = 0;
  // for (int i = 0; i < n; ++i) {
  //   cin >> base[i];
  // }
  // for (int i = 0; i < n; ++i) {
  //   cin >> add[i];
  // }
  // for (int i = 0; i < n; ++i) {
  //   origin.push_back(make_pair(base[i], add[i]));
  // }
  // priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap(origin.begin(), origin.end());

  // for (int i = 0; i < n; ++i) {
  //   priority_queue<pair<int, int>, vector<pair<int, int>>> tempHeap;
  //   tempHeap.swap(maxHeap);
  //   for (int j = 0; j < n; ++j) {
  //     auto top = tempHeap.top();
  //     tempHeap.pop();
  //     if (j == 0) {
  //       cout << i + 1 << "day " << top.first << '\n';
  //       ans += top.first;
  //       maxHeap.push(make_pair(top.second, top.second));
  //     } else {
  //       maxHeap.push(make_pair(top.first + top.second, top.second));
  //     }
  //   }
  // }

  // cout << ans;

  return 0;
}