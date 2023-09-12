#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<string> words(n);
  vector<string> ans(2 * n - 1);
  int wordLen = 0;
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
    wordLen += words[i].length();
  }
  int totalSpace = m -  wordLen;
  int spacePerWord = totalSpace / (n - 1);
  int remain = totalSpace - (spacePerWord * (n - 1));
  for (int i = 0, j = 0; i < ans.size(); i += 2, ++j) {
    if (i == 0) {
      ans[i] = words[i];
    } else {
      for (int k = 0; k < spacePerWord; ++k) {
        ans[i - 1].push_back('_');
      }
      if (islower(words[j][0])) {
        if (remain) {
          ans[i - 1].push_back('_');
          --remain;
        }
      }
      ans[i] = words[j];
    }
  }
  if (remain) {
    for (int i = ans.size() - 1, j = words.size() - 1; i > 0; i -= 2, --j) {
      if (isupper(words[j][0])) {
        if (remain) {
          ans[i - 1].push_back('_');
          --remain;
        }
      }
    }
  }
  string ret = "";
  for (size_t i = 0; i < ans.size(); ++i) {
    ret += ans[i];
  }
  cout << ret;
  return 0;
}