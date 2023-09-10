#include <iostream>
#include <vector>

using namespace std;

vector<string> a;
vector<string> b;
void change(int row, int col) {
  for (int i = row; i < row + 3; ++i) {
    for (int j = col; j < col + 3; ++j) {
      if (a[i][j] == '0') {
        a[i][j] = '1';
      } else {
        a[i][j] = '0';
      }
    }
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
      string val;
      cin >> val;
      a.push_back(val);
  }
  for (int i = 0; i < n; ++i) {
      string val;
      cin >> val;
      b.push_back(val);
  }
  for (int i = 0; i < n - 2; ++i) {
    for (int j = 0; j < m  - 2; ++j) {
      if (a[i][j] != b[i][j]) {
        change(i, j);
        ans++;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) {
        ans = -1;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}