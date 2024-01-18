// #include <cstdio>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
// 후위 순회를 통한  수식 계산 구현
float leftNum, rightNum, result;
struct Node {
  string s;
  int left = 0;
  int right = 0;
};

bool isOperator(string s) {
  if (s == "*" || s == "/" || s == "+" || s == "-") {
    return true;
  }
  return false;
}

float doOperation(float left, float right, string op) {
  if (op == "*") {
    return left * right;
  } else if (op == "/") {
    return left / right;
  } else if (op == "+") {
    return left + right;
  } else {
    return left - right;
  }
}

float calculate(Node tree[], int ptr) {
  if (ptr == 0) {
    return 0;
  }
  string curData = tree[ptr].s;
  int left = calculate(tree, tree[ptr].left);
  int right = calculate(tree, tree[ptr].right);
  if (isOperator(curData)) {
    return doOperation(left, right, curData);
  } else {
    return static_cast<float>(stoi(curData));
  }
}

int main(int argc, char **argv) {
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
  // freopen("input.txt", "r", stdin);
  /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
  */
  T = 10;
  for (test_case = 1; test_case <= T; ++test_case) {
    int n;
    Node tree[1001];
    cin >> n;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
      string line;
      getline(cin, line);
      istringstream iss(line);

      int ptr;
      string s;
      int left = 0;
      int right = 0;

      iss >> ptr >> s;
      if (iss >> left) {
        iss >> right;
      }
      tree[ptr].s = s;
      tree[ptr].left = left;
      tree[ptr].right = right;
    }
    cout << "#" << test_case << " ";
    cout << calculate(tree, 1) << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}
