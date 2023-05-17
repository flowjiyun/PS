#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPair(int n, bool taken[10], bool pairFriend[10][10]) {
  int next = -1;
  for (int i = 0; i < n; ++i) {
    if (taken[i] == 0) {
      next = i;
      break;
    }
  }
  if (next == -1) {
    cout << "done" << '\n';
    return 1;
  }
  int ret = 0;
    for (int pair = next + 1; pair < n; ++pair ) {
      cout << "pair index : " << pair << '\n';
      if (taken[pair] == false && pairFriend[next][pair] == true) {
        taken[next] = true;
        taken[pair] = true;
        cout << "pair : " << next << " " << pair << '\n';
        ret += countPair(n, taken, pairFriend);
        taken[next] = false;
        taken[pair] = false;
      }
    }
  return ret;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //input
  int c, n, m;
  vector<int> pairInput;
  cin >> c;
  while (c--) {
    cin >> n >> m;
    for (int i = 0; i < m * 2; ++i) {
      int val;
      cin >> val;
      pairInput.push_back(val);
    }
    bool pairFriend[10][10] = {0};
    bool taken[10] = {0};
    for (size_t i = 0; i < pairInput.size(); i += 2) {
      pairFriend[pairInput[i]][pairInput[i + 1]] = true;
      pairFriend[pairInput[i + 1]][pairInput[i]] = true;
    }
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        cout << pairFriend[i][j] << ' ';
      }
      cout << '\n';
    }

    cout << countPair(n, taken, pairFriend) << '\n';
  }

  return 0;
}