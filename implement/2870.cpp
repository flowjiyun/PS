#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string line, num;
  vector<string> ret;
  cin >> n;
  while (n--) {
    cin >> line;
    num = "";
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] >= '0' && line[i] <= '9') {
        num += line[i];
      }
      else if (num.size()) {
        
      }
    }
  }
  return (0);
}