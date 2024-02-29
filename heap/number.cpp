#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int n;
    cin >> n;
    int data[10];
    for (int i = 0; i < n; ++i) {
      cin >> data[i];
    }
    int k;
    cin >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minHeap;
    minHeap.push({0, k});
    int ret;
    while (!minHeap.empty()) {
      auto [cnt, remain] = minHeap.top();
      minHeap.pop();
      if (remain == 0) {
        ret = cnt;
        break;
      }
      for (int i = 0; i < n; ++i) {
        minHeap.push({cnt + (remain % data[i]), remain / data[i]});
      }
    }
    cout << "#" << test_case << " " << ret << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}