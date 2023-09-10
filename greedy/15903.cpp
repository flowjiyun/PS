#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<long long> seq(n);
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }
  priority_queue<long long, vector<long long>, greater<long long> > minHeap(seq.begin(), seq.end());
  for (int i = 0; i < m; ++i) {
    long long first = minHeap.top();
    minHeap.pop();
    long long second = minHeap.top();
    minHeap.pop();
    long long sum = first + second;
    minHeap.push(sum);
    minHeap.push(sum);
  }
  long long ans = 0;
  while (!minHeap.empty()) {
    ans += minHeap.top();
    minHeap.pop();
  }
  cout << ans;
  return 0;
}