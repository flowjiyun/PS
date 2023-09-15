#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<float> scores(n);
  for (int i = 0; i < n; ++i) {
    cin >> scores[i];
  }
  priority_queue<float, vector<float>, greater<float> > minHeap(scores.begin(), scores.end());
  for (int i = 0; i < 7; ++i) {
    float val = minHeap.top();
    minHeap.pop();
    cout << fixed;
    cout.precision(3);
    cout << val << '\n';
  }
  return 0;
}