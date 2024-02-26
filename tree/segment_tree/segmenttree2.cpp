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
    int n, q, halfN;
    vector<int> evenData;
    vector<int> oddData;
    cin >> n >> q;

    if (n % 2 == 0) {
      halfN = n / 2;
    } else {
      halfN = (n + 1) / 2;
    }

    // index 기준 짝수 및 홀수 데이터 나눠서 저장해서 segment tree 만들기
    evenData.resize(halfN);
    oddData.resize(halfN);
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        cin >> evenData[i / 2];
      } else {
        cin >> oddData[i / 2];
      }
    }

    SegmentTree evenTree(
        halfN, evenData, [](int a, int b) { return a + b; }, 0);
    SegmentTree oddTree(
        halfN, oddData, [](int a, int b) { return a + b; }, 0);

    cout << "#" << test_case << " ";
    for (int i = 0; i < q; ++i) {
      int command, a, b;
      cin >> command >> a >> b;
      if (command == 0) {
        if (a % 2 == 0) {
          evenTree.updateTree(a / 2, b, 1, 0, halfN - 1);
        } else {
          oddTree.updateTree(a / 2, b, 1, 0, halfN - 1);
        }
      } else {
        // 쿼리 시작 인덱스가 짝수, 홀수 경우의 수 나누기
        // 쿼리 사이즈가 1개 일경우 1개 이상일 경우
        int qSize = b - a;
        int halfQSize = qSize / 2;
        int evenStartIndex;
        int oddStartIndex;
        int evenEndIndex;
        int oddEndIndex;
        int ret;
        if (a % 2 == 0) {
          evenStartIndex = a / 2;
          oddStartIndex = evenStartIndex;
          if (qSize % 2 == 0) {
            evenEndIndex = evenStartIndex + halfQSize - 1;
            oddEndIndex = oddStartIndex + halfQSize - 1;
          } else {
            evenEndIndex = evenStartIndex + halfQSize;
            oddEndIndex = oddStartIndex + halfQSize - 1;
          }
          ret = evenTree.query(evenStartIndex, evenEndIndex, 1, 0, halfN - 1) -
                oddTree.query(oddStartIndex, oddEndIndex, 1, 0, halfN - 1);
        } else {
          oddStartIndex = a / 2;
          evenStartIndex = oddStartIndex + 1;
          if (qSize % 2 == 0) {
            oddEndIndex = oddStartIndex + halfQSize - 1;
            evenEndIndex = evenStartIndex + halfQSize - 1;
          } else {
            oddEndIndex = oddStartIndex + halfQSize;
            evenEndIndex = evenStartIndex + halfQSize - 1;
          }
          ret = oddTree.query(oddStartIndex, oddEndIndex, 1, 0, halfN - 1) -
                evenTree.query(evenStartIndex, evenEndIndex, 1, 0, halfN - 1);
        }
        cout << ret << " ";
      }
    }
    cout << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}