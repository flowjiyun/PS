#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

bool visited[101];
int seq[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> tools;
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    cin >> seq[i];
  }
  for (int i = 0; i < k; ++i) {
    if (!visited[seq[i]]) {
      if (static_cast<int>(tools.size()) == n) {
        int prevRef = 0;
        int pos;
        for (auto tool : tools) {
          int curRef = numeric_limits<int>::max();
          for (int j = i + 1; j < k; ++j) {
            if(tool == seq[j]) {
              curRef = j;
              break;
            }
          }
          if (prevRef < curRef) {
            prevRef = curRef;
            pos = tool;
          }
        }
        visited[pos] = 0;
        ++ans;
        tools.erase(find(tools.begin(), tools.end(), pos));
      } 
      tools.push_back(seq[i]);
      visited[seq[i]] = true;
    }
  }
  cout << ans;
  return 0;
}