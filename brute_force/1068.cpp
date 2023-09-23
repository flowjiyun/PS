#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[51];
int n, removeIndex, root;

int dfs(int curNode) {
  int childCnt = 0;
  if (tree[curNode].size() == 0) {
    return 1;
  }
  for (auto nextNode : tree[curNode]) {
    if (nextNode == removeIndex) {
      continue;
    }
    childCnt += dfs(nextNode);
  }
  return childCnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    if (val == -1) {
      root = i;
    } else {
      tree[val].push_back(i);
    }
  }
  cin >> removeIndex;

  if (removeIndex == root) {
    cout << '0' << '\n';
    return 0;
  }
  cout << dfs(root) << '\n';

  return 0;
}