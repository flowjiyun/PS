// 라이브러리 없이 heap 구현하기
// 구현할 함수
// 1. swap
// 2. push
// 3. top
// 4. pop
static const int MAX_VAL = 100000;

struct Info {
  int uID;
  int income;
};

void swap(Info &a, Info &b) {
  Info temp = a;
  a = b;
  b = temp;
}

class MaxHeap {
public:
  MaxHeap() = default;

  int getSize() const { return mSize; }

  void push(Info val) {
    mData[++mSize] = val;

    int index = mSize;
    int parent = mSize / 2;

    while (parent != 0 && mData[index].income > mData[parent].income) {
      swap(mData[index], mData[parent]);

      index /= 2;
      parent = index / 2;
    }
  }

  Info top() { return mData[1]; }

  void pop() {
    mData[1] = mData[mSize--];

    // 맨위로 올린 데이터 제자리 찾아가게 만들기
    int parentIndex = 1;

    int largeIndex = parentIndex;
    int leftChildIndex = parentIndex * 2;
    int rightChildIndex = parentIndex * 2 + 1;

    while (true) {
      if (leftChildIndex <= mSize &&
          mData[leftChildIndex].income > mData[largeIndex].income) {
        largeIndex = leftChildIndex;
      }
      if (rightChildIndex <= mSize &&
          mData[rightChildIndex].income > mData[largeIndex].income) {
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

  int getTopN(Info *tmp, int n) {
    if (mSize < n) {
      n = mSize;
    }
    MaxHeap tmpHeap;
    for (int i = 1; i <= mSize; ++i) {
      tmpHeap.push(mData[i]);
    }
    for (int i = 0; i < n; ++i) {
      tmp[i] = tmpHeap.top();
      tmpHeap.pop();
    }
    return n;
  }

public:
  Info mData[MAX_VAL + 1];
  int mSize = 0;
};

MaxHeap maxHeap;

void init() {
  maxHeap = MaxHeap();
  return;
}

void addUser(int uID, int income) {
  Info tmp;
  tmp.uID = uID;
  tmp.income = income;
  maxHeap.push(tmp);
}

int getTop10(int result[10]) {
  Info tmp[10];
  int ret = maxHeap.getTopN(tmp, 10);

  for (int i = 0; i < ret; ++i) {
    result[i] = tmp[i].uID;
  }
  return ret;
}