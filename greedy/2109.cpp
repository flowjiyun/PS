#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
  if (a.second == b.second) {
    return a.first > b.first;
  }
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> lectures(n);
  for (int i = 0; i < n; ++i) {
    cin >> lectures[i].first >> lectures[i].second;
  }
  sort(lectures.begin(), lectures.end(), compare);

  priority_queue<int, vector<int>, greater<int>> minHeap;
  for (int i = 0; i < n; ++i) {
    int curDay = lectures[i].second;
    minHeap.push(lectures[i].first);
    while (minHeap.size() > curDay) {
      minHeap.pop();
    }
  }
  int ans = 0;
  while (!minHeap.empty()) {
    ans += minHeap.top();
    minHeap.pop();    
  }
  cout << ans;
  return 0;
}