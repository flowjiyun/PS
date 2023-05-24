#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int linked[10][16];

bool isAlign(std::vector<int>& clocks) {
  for (int i = 0; i < 16; ++i) {
    if (clocks[i] != 12) {
      return false;
    }
  }
  return true;
}

void push(std::vector<int> &clocks, int sw) {
  for (int i = 0; i < 16; ++i) {
    if (linked[sw][i] == 1) {
      clocks[i] += 3;
      if (clocks[i] == 15) {
        clocks[i] = 3;
      }
    }
  }
}

int solved(std::vector<int> &clocks, int sw) {
  if (sw == 10) {
    if (isAlign(clocks)) {
      return 0;
    } else {
      return 9999;
    }
  }
  int ret = 9999;
  for (int cnt = 0; cnt < 4; ++cnt) {
    ret = std::min(ret, cnt + solved(clocks, sw + 1));
    push(clocks, sw);
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  std::vector<int> clocks;
  for (int i = 0; i < 10; ++i) {
    int sw, val;
    cin >> sw;
    for (int j = 0; j < sw; ++j) {
      cin >> val;
      linked[i][val] = 1;
    }
  }
  for (int i = 0; i < 16; ++i) {
    int val;
    cin >> val;
    clocks.push_back(val);
  }

  cout << solved(clocks, 0);

  return 0;
}