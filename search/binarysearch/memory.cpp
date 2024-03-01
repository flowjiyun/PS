#include <iostream>

using namespace std;

const int MAX_VAL = 200000;

int wearLevel[MAX_VAL + 1];
int blockInfo[MAX_VAL + 1];

bool isOK(int val, int n, int k) {
  int curK = 0;

  for (int start = 0; start < n; ++start) {
    if (wearLevel[start] > val) {
      continue;
    }

    int end = start + blockInfo[curK];
    for (int i = start; i < end && i < n; ++i) {
      if (wearLevel[i] > val) {
        start = i;
        break;
      }
      if (i == end - 1) {
        start = i;
        ++curK;
      }
    }
    if (curK == k) {
      return true;
    }
  }
  return false;
}

int solve(int n, int k) {
  int left = 1;
  int right = MAX_VAL;
  int answer = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (isOK(mid, n, k)) {
      answer = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return answer;
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> wearLevel[i];
    }
    for (int i = 0; i < k; ++i) {
      cin >> blockInfo[i];
    }

    cout << "#" << test_case << " " << solve(n, k) << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}