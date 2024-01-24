#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const long long MAX_VAL = numeric_limits<long long>::max();

bool isTarget(vector<long long> &candyCntList, long long bagCnt,
              long long target) {
  long long sum = 0;
  if (bagCnt == 0) {
    return 1;
  }
  for (const long long val : candyCntList) {
    sum += (val / bagCnt);
  }
  if (sum >= target) {
    return 1;
  } else {
    return 0;
  }
}

long long getBestCnt(vector<long long> &candyCntList, long long left,
                     long long right, long long target) {
  if (left > right) {
    return -1;
  }

  long long curMax = -1;
  long long mid = left + ((right - left) / 2);

  bool ret = isTarget(candyCntList, mid, target);
  if (ret == 1) {
    curMax = mid;
    curMax = max(curMax, getBestCnt(candyCntList, mid + 1, right, target));
  } else {
    curMax = getBestCnt(candyCntList, left, mid - 1, target);
  }
  if (curMax == -1) {
    return 0;
  }
  return curMax;
}

int main(int argc, char **argv) {
  int test_case;
  int T;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;

  for (test_case = 1; test_case <= T; ++test_case) {
    int n;
    long long m;
    vector<long long> candyCntList;
    cin >> n >> m;

    long long maxParameter = 0;
    for (int i = 0; i < n; ++i) {
      long long val;
      cin >> val;
      maxParameter = max(maxParameter, val);
      candyCntList.push_back(val);
    }

    cout << "#" << test_case << " "
         << getBestCnt(candyCntList, 0, maxParameter, m) << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}