#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int maxCnt = 0;
vector<int> list;
const string pre = "acitn";

void combi(int index, int count, int mask) {
  if (count == k) {
    int cnt = 0;
    for (auto val : list) {
      if ((val & mask) == val) {
        ++cnt;
      }
    }
    maxCnt = max(maxCnt, cnt);
    return;
  }
  for (int i = index; i < 26; ++i) {
    if (i == 'a' - 'a' || i == 'n' - 'a' || i == 't' - 'a' || i == 'c' - 'a' || i == 'i' - 'a') {
      continue;
    }
    mask |= (1 << i);
    combi(i + 1, count + 1, mask);
    mask &= ~(1 << i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    string value;
    int word = 0;
    cin >> value;
    for (auto c : value) {
      word |= (1 << (c - 'a'));
    }
    list.push_back(word);
  }
  if (k < 5) {
    cout << "0";
    return 0;
  }

  int mask = 0;
  for (char c : pre) {
    mask |= (1 << (c - 'a'));
  }
  combi(0, 5, mask);
  cout << maxCnt;
  return 0;

}