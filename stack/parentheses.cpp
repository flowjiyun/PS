#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
  stack<char> check;
  unordered_map<char, char> matching {{'(',')'}, {'{','}'}, {'[',']'}};

  for (char c : s) {
    if (matching.find(c) != matching.end()) {
      check.push(c);
    } else {
      if (check.empty()) {
        return false;
      }
      char curr_open = check.top();
      if (matching[curr_open] != c) {
        return false;
      }
      check.pop();
    }
  }
  return check.empty();
}