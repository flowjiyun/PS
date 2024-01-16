#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  char c = 0;
  int left = 0;
  int right = 0;
};

void InOrder(Node tree[], int ptr) {
  if (tree[ptr].left != 0) {
    InOrder(tree, tree[ptr].left);
  }
  cout << tree[ptr].c;
  if (tree[ptr].right != 0) {
    InOrder(tree, tree[ptr].right);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test_case;
  int T;
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
  T = 10;
  /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
  */

  for (test_case = 1; test_case <= T; ++test_case) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Node tree[101];
    for (int i = 0; i < n; ++i) {
      string line;
      getline(cin, line);
      istringstream iss(line);
      int ptr;
      char c;
      int left = 0;
      int right = 0;
      iss >> ptr >> c;
      if (iss >> left) {
        iss >> right;
      }
      tree[ptr].c = c;
      tree[ptr].left = left;
      tree[ptr].right = right;
    }
    cout << "#" << test_case << " ";
    InOrder(tree, 1);
    cout << "\n";
  }
  return 0;
}