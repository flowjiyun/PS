#include <cmath>
#include <iostream>
using namespace std;

// 2차 방정식의 해를 찾는데 이분탐식을 활용
// - 단순위 선형적으로 대입해 보는 것이 아닌 절반으로 나눠 가면서 대입해서 값
// 찾아 보기
long long getNofTriangle(long long n, long long left, long long right) {
  if (left > right) {
    return -1;
  }
  long long mid = left + ((right - left) / 2);
  // long long 계산 값 overflow 방지
  long long x = mid;
  long long y = mid + 1;
  if (x % 2 == 0) {
    x /= 2;
  } else {
    y /= 2;
  }
  long long solution = x * y;
  if (solution == n) {
    return mid;
  } else if (solution < n) {
    return getNofTriangle(n, mid + 1, right);
  } else {
    return getNofTriangle(n, left, mid - 1);
  }
}

int main(int argc, char **argv) {
  int test_case;
  int T;
  ios::sync_with_stdio(0);
  cin.tie(0);
  /*
     아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의
     코드입니다.
     //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을
     저장한 후, freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신
     파일로부터 입력을 받아올 수 있습니다. 따라서 테스트를 수행할 때에는 아래
     주석을 지우고 이 함수를 사용하셔도 좋습니다. freopen 함수를 사용하기
     위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다. 단,
     채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리
     하셔야 합니다.
  */
  // freopen("input.txt", "r", stdin);
  cin >> T;
  /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
  */
  for (test_case = 1; test_case <= T; ++test_case) {
    long long n;
    cin >> n;
    // max_val을 단순히 n으로 하면 solution 계산시 overflow 발생할 수 있음
    long long max_val = static_cast<long long>(sqrt(2 * n)) + 1;
    cout << "#" << test_case << " " << getNofTriangle(n, 0, max_val) << "\n";
  }

  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}