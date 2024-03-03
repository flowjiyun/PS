#include <iostream>
#include <string>

using namespace std;

const int base = 31; // 알파벳 26보다 큰 소수 사용
int pows[2002 * 2002];
int textHashSum[2002][2002]; // i번째 행의 1 ~ j번쨰 글자까지 해쉬 값의 누적합

int getHash(int r, int s, int e) {
  int length = e - s + 1;
  return textHashSum[r][e + 1] - textHashSum[r][s] * pows[length];
}

int solve() {
  int answer = 0;
  int h, w, n, m;
  cin >> h >> w >> n >> m;

  // pattern hash 만들기
  int pHash = 0;
  for (int i = 0; i < h; ++i) {
    string val;
    cin >> val;
    for (int j = 0; j < w; ++j) {
      pHash = pHash * base + val[j];
    }
  }
  for (int i = 0; i < n; ++i) {
    string val;
    cin >> val;
    textHashSum[i][0] = 0;
    for (int j = 0; j < m; ++j) {
      textHashSum[i][j + 1] = textHashSum[i][j] * base + val[j];
    }
  }

  for (int i = 0; i < m - w + 1; ++i) {
    int textHash = 0;
    for (int j = 0; j < h; ++j) {
      // 각행의 해쉬값 더해서 패턴과 같은 형태로 만들기
      textHash = textHash * pows[w] + getHash(j, i, i + w - 1);
    }
    if (textHash == pHash) {
      ++answer;
    }
    // 아래로 내려가면서 그림 있나 찾아 보기
    // 위에 한줄 빼고 아래 한줄 더하면서 textHash 값 갱신
    for (int j = h; j < n; ++j) {
      textHash = textHash - getHash(j - h, i, i + w - 1) * pows[w * (h - 1)];
      textHash = textHash * pows[w] + getHash(j, i, i + w - 1);
      if (textHash == pHash) {
        ++answer;
      }
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
  pows[0] = 1;
  for (int i = 1; i < 2002 * 2002; ++i) {
    pows[i] = pows[i - 1] * base;
  }
  for (test_case = 1; test_case <= T; ++test_case) {
    cout << "#" << test_case << " " << solve() << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}