#include <iostream>
#include <string>
#include <vector>
#include <stack>

//괄호찾기 문제 활용하는 문제

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> words;
  while (1) {
    string val;
    cin >> val;
    if (val[0] == '-') {
      break;
    }
    words.push_back(val);
  }
  for (size_t i = 0; i < words.size(); ++i) {
    int cnt = 0;
    stack<char> check;
    for (size_t j = 0; j < words[i].size(); ++j) {
      if (words[i][j] == '{') {
        check.push('{');
      } else {
        if (check.empty()) {
          cnt++;
          check.push('{');
        } else {
          check.pop();
        }
      }
    }
    cnt += (check.size() / 2);
    cout << i + 1 << ". " << cnt << '\n';
  }
  return 0;
}