#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct SegmentTree {

  SegmentTree(int n, vector<int> &data, function<int(int, int)> merge, int def)
      : mData(data), mMerge(merge), mDefault(def) {
    mTreeSize = n;
    mTree.resize(4 * n);
    makeTree(1, 0, mTreeSize - 1);
  }

  int makeTree(int nodeID, int left, int right) {
    // leaf node
    if (left == right) {
      return mTree[nodeID] = mData[left];
    }
    int mid = left + (right - left) / 2;
    int leftChild = makeTree(2 * nodeID, left, mid);
    int rightChild = makeTree(2 * nodeID + 1, mid + 1, right);
    return mTree[nodeID] = mMerge(leftChild, rightChild);
  }

  // update query (point update)
  int updateTree(int index, int newVal, int nodeID, int left, int right) {
    // out of range
    if (index < left || right < index) {
      return mTree[nodeID];
    }
    // leaf nodeID
    if (left == right) {
      return mTree[nodeID] = newVal;
    }

    int mid = left + (right - left) / 2;
    int leftChild = updateTree(index, newVal, 2 * nodeID, left, mid);
    int rightChild = updateTree(index, newVal, 2 * nodeID + 1, mid + 1, right);
    return mTree[nodeID] = mMerge(leftChild, rightChild);
  }

  // range query
  // start, end = > query range
  // left, right => tree range
  int query(int start, int end, int nodeID, int left, int right) {
    if (end < left || right < start) {
      return mDefault;
    }
    if (start <= left && right <= end) {
      return mTree[nodeID];
    }

    int mid = left + (right - left) / 2;
    int leftChild = query(start, end, 2 * nodeID, left, mid);
    int rightChild = query(start, end, 2 * nodeID + 1, mid + 1, right);
    return mMerge(leftChild, rightChild);
  }

  void printTree() {
    for (const auto &v : mTree) {
      cout << v << " ";
    }
    cout << "\n";
  }

  int mTreeSize;
  vector<int> mTree;
  vector<int> mData;
  function<int(int, int)> mMerge;
  int mDefault;
};

int main(int argc, char **argv) {
  int test_case;
  int T;
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int n, q;
    vector<int> data;
    cin >> n >> q;
    data.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> data[i];
    }
    SegmentTree minTree(
        n, data, [](int a, int b) { return min(a, b); },
        numeric_limits<int>::max());
    SegmentTree maxTree(
        n, data, [](int a, int b) { return max(a, b); },
        numeric_limits<int>::min());
    cout << "#" << test_case << " ";
    for (int i = 0; i < q; ++i) {
      int command, a, b;
      cin >> command >> a >> b;
      if (command == 0) {
        minTree.updateTree(a, b, 1, 0, n - 1);
        maxTree.updateTree(a, b, 1, 0, n - 1);
      } else {
        int maxVal = maxTree.query(a, b - 1, 1, 0, n - 1);
        int minVal = minTree.query(a, b - 1, 1, 0, n - 1);
        int ret = maxVal - minVal;
        cout << ret << " ";
      }
    }
    cout << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}