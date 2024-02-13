#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  int test_case;
  int T;
  // freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int k;
    string val;
    vector<string> suffixList;
    cin >> k;
    cin >> val;
    for (int i = 0; i < val.size(); ++i) {
      suffixList.push_back(val.substr(i));
    }
    sort(suffixList.begin(), suffixList.end());
    cout << "#" << test_case << " " << suffixList[k - 1] << "\n";
  }
  return 0;
}