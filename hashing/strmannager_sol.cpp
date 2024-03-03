#include <cstring>
#include <deque>
std::deque<char> str;
int hashCnt[1 << 20];
bool isReversed;

void hashBack(int delta) {
  int hash = 0;
  for (int i = str.size() - 1, j = 0; i >= 0 && j < 4; --i, ++j) {
    hash <<= 5;
    hash += (str[i] - 'a' + 1);
    hashCnt[hash] += delta;
  }
}

void hashFront(int delta) {
  int hash = 0;
  int pow = 1;
  for (int i = 0; i < str.size() && i < 4; ++i) {
    hash += pow * (str[i] - 'a' + 1);
    pow <<= 5;
    hashCnt[hash] += delta;
  }
}

void pushBack(char c) {
  str.push_back(c);
  hashBack(1);
}

void pushFront(char c) {
  str.push_front(c);
  hashFront(1);
}

void popBack() {
  hashBack(-1);
  str.pop_back();
}

void popFront() {
  hashFront(-1);
  str.pop_front();
}

void init(char mStr[]) {
  str.clear();
  memset(hashCnt, 0, sizeof(hashCnt));
  isReversed = false;

  for (int i = 0; mStr[i] != 0; ++i) {
    pushBack(mStr[i]);
  }
}

void appendWord(char mWord[]) {
  if (isReversed) {
    for (int i = 0; mWord[i] != 0; ++i) {
      pushFront(mWord[i]);
    }
  } else {
    for (int i = 0; mWord[i] != 0; ++i) {
      pushBack(mWord[i]);
    }
  }
}

void cut(int k) {
  if (isReversed) {
    for (int i = 0; i < k; ++i) {
      popFront();
    }
  } else {
    for (int i = 0; i < k; ++i) {
      popBack();
    }
  }
}

void reverse() { isReversed = !isReversed; }

int countOccurrence(char mWord[]) {
  int hash = 0;
  int pow = 1;
  if (isReversed) {
    // abc
    // hash : cba
    for (int i = 0; mWord[i] != 0; ++i) {
      hash <<= 5;
      hash += (mWord[i] - 'a' + 1);
    }
  } else {
    // abc
    // hash : a + pow^1 * b + pow^2 * c;
    for (int i = 0; mWord[i] != 0; ++i) {
      hash += pow * (mWord[i] - 'a' + 1);
      pow <<= 5;
    }
  }

  return hashCnt[hash];
}