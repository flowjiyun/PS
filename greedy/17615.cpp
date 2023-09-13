#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  string seq;
  cin >> seq;

  int minVal = numeric_limits<int>::max();
  //r left sort with r
  
  int cnt = 0;
  bool flag = true;
  for (int i = 0; i < seq.size(); ++i) {
    if (i != 0 && seq[i - 1] == 'R' && seq[i] == 'B') {
      flag = false;
    }
    if (!flag && seq[i] == 'R') {
      ++cnt;
      // cout << "first : " << i << "\n";
      // cout << "cnt: " << cnt << "\n";
    }
  }
  minVal = min(minVal, cnt);
  cnt = 0;
  flag = true;
  for (int i = seq.size() - 1; i >= 0; --i) {
    if (i != seq.size() - 1 && seq[i + 1] == 'R' && seq[i] == 'B') {
      flag = false;
    }
    if (!flag && seq[i] == 'B') {
      ++cnt;
      // cout << "second : " << i << "\n";
      // cout << "cnt: " << cnt << "\n";
    }
  }
  minVal = min(minVal, cnt);
  cnt = 0;
  flag = true;
  for (int i = 0; i < seq.size(); ++i) {
    if (i != 0 && seq[i - 1] == 'R' && seq[i] == 'B') {
      flag = false;
    }
    if (!flag && seq[i] == 'B') {
      ++cnt;
      // cout << "third : " << i << "\n";
      // cout << "cnt: " << cnt << "\n";
    }
  }
  minVal = min(minVal, cnt);
  cnt = 0;
  flag = true;
  for (int i = seq.size() - 1; i >= 0; --i) {
    if (i != seq.size() - 1 && seq[i + 1] == 'B' && seq[i] == 'R') {
      flag = false;
    }
    if (!flag && seq[i] == 'R') {
      ++cnt;
      // cout << "forth : " << i << "\n";
      // cout << "cnt: " << cnt << "\n";
    }
  }
  minVal = min(minVal, cnt);

  cout << minVal;
  return 0;
}