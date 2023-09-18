#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> problems(n);
  for (int i = 0; i < n; ++i) {
    cin >> problems[i].first >> problems[i].second;
  }

  sort(problems.begin(), problems.end());

  priority_queue<int, vector<int>, greater<int>> minHeap;
  for (int i = 0; i < n; ++i) {
    int curDeadLine = problems[i].first;
    minHeap.push(problems[i].second);
    while(minHeap.size() > curDeadLine)  {
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