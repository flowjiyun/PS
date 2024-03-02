#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPmt(const string &p) {
  int patternSize = p.size();
  vector<int> ret(patternSize, 0);
  int j = 0;
  for (int i = 1; i < patternSize; ++i) {
    while (j > 0 && p[i] != p[j]) {
      j = ret[j - 1];
    }
    if (p[i] == p[j]) {
      ret[i] = ++j;
    }
  }
  return ret;
}

int kmp(const string &t, const string &p) {
  int textSize = t.size();
  int patternSize = p.size();
  int j = 0;
  int ret = 0;
  vector<int> pmt = getPmt(p);
  for (int i = 0; i < textSize; ++i) {
    while (j > 0 && t[i] != p[j]) {
      j = pmt[j - 1];
    }
    if (t[i] == p[j]) {
      if (j == patternSize - 1) {
        ret++;
        j = pmt[j];
      } else {
        j++;
      }
    }
  }
  return ret;
}

int main(int argc, char **argv) {
  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    string t, p;
    cin >> t >> p;
    cout << "#" << test_case << " " << kmp(t, p) << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}