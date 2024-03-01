#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> hashMap;
int main(int argc, char **argv) {
  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    hashMap.clear();
    int n, m;
    int answer = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      string val;
      cin >> val;
      hashMap[val]++;
    }
    for (int i = 0; i < m; ++i) {
      string val;
      cin >> val;
      if (hashMap.count(val)) {
        ++answer;
      }
    }
    cout << "#" << test_case << " " << answer << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}