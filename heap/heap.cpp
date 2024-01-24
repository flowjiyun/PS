#include <iostream>

using namespace std;

// 라이브러리 없이 heap 구현하기
// 구현할 함수
// 1. swap
// 2. push
// 3. top
// 4. pop

const int MAX_VAL = 100000;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

class MaxHeap {
public:
  MaxHeap() = default;

  int getSize() const { return mSize; }

  void push(int val) {
    mData[++mSize] = val;

    int index = mSize;
    int parent = mSize / 2;

    while (parent != 0 && mData[index] > mData[parent]) {
      swap(mData[index], mData[parent]);

      index /= 2;
      parent = index / 2;
    }
  }

  int top() { return mData[1]; }

  void pop() {
    mData[1] = mData[mSize--];

    // 맨위로 올린 데이터 제자리 찾아가게 만들기
    int parentIndex = 1;

    int largeIndex = parentIndex;
    int leftChildIndex = parentIndex * 2;
    int rightChildIndex = parentIndex * 2 + 1;

    while (true) {
      if (leftChildIndex <= mSize &&
          mData[leftChildIndex] > mData[largeIndex]) {
        largeIndex = leftChildIndex;
      }
      if (rightChildIndex <= mSize &&
          mData[rightChildIndex] > mData[largeIndex]) {
        largeIndex = rightChildIndex;
      }
      if (largeIndex == parentIndex) {
        break;
      } else {
        swap(mData[parentIndex], mData[largeIndex]);
        parentIndex = largeIndex;
        leftChildIndex = parentIndex * 2;
        rightChildIndex = parentIndex * 2 + 1;
      }
    }
  }

public:
  int mData[MAX_VAL + 1];
  int mSize = 0;
};

MaxHeap maxHeap;

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
    MaxHeap maxHeap;
    int n;
    cin >> n;
    cout << "#" << test_case << " ";

    for (int i = 0; i < n; ++i) {
      int command;
      cin >> command;
      if (command == 1) {
        int val;
        cin >> val;
        maxHeap.push(val);
      } else {
        if (maxHeap.getSize() != 0) {
          cout << maxHeap.top() << " ";
          maxHeap.pop();
        } else {
          cout << "-1"
               << " ";
        }
      }
    }
    cout << "\n";
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}