#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 누적 합을 사용하여 공백인 일 수를 관리
// 1 3 5 7
// days[0] = 0
// days[1] = 3 - 1 - 1 = 1
// days[2] = 1 +  5 - 3 - 1 = 2
vector<int> blankPreSum;
int maxVal;
int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    maxVal = 0;
    blankPreSum.clear();
    blankPreSum.push_back(0);
    int n, p;
    cin >> n >> p;
    vector<int> day(n);
    for (int i = 0; i < n; ++i) {
      cin >> day[i];
    }
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
      sum += (day[i + 1] - day[i] - 1);
      blankPreSum.push_back(sum);
    }
    // 시작 위치를 조절해 가면서 최장 strict 찾아 보기
    for (int i = 0; i < n; ++i) {
      int left = i;
      int right = n - 1;
      int curSum = 0;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        int curP = p;
        int curBlankSum = blankPreSum[mid] - blankPreSum[i];
        curP = (p - curBlankSum > 0) ? p - curBlankSum : 0;

        if (curBlankSum > p) {
          right = mid - 1;
        } else {
          curSum = day[mid] - day[i] + 1 + curP;
          left = mid + 1;
        }
      }
      maxVal = max(maxVal, curSum);
    }
    cout << "#" << test_case << " " << maxVal << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}
