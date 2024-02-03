#include <cstring>
#include <deque>
#include <iostream>

int h, w;
int alpaCount[300][26];
int curRow, curCol;
int wordCnt;
std::deque<char> lines[300];

void init(int H, int W, char mStr[]) {
  // 자료 구조 및  변수 초기화
  h = H;
  w = W;
  curRow = 0;
  curCol = 0;
  wordCnt = 0;
  memset(alpaCount, 0, sizeof(alpaCount));
  for (int i = 0; i < H; ++i) {
    lines[i].clear();
  }
  // 문자 대입
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (mStr[wordCnt]) {
        alpaCount[i][mStr[wordCnt] - 'a']++;
        lines[i].push_back(mStr[wordCnt]);
        ++wordCnt;
      } else {
        break;
      }
    }
  }
}

void insert(char mChar) {
  ++wordCnt;
  lines[curRow].insert(lines[curRow].begin() + curCol, mChar);
  alpaCount[curRow][mChar - 'a']++;
  int delta = 0;
  // 행을 넘어가는 문자 넘기기
  while (lines[curRow + delta].size() > w) {
    char lastChar = lines[curRow + delta].back();
    lines[curRow + delta].pop_back();
    alpaCount[curRow + delta][lastChar - 'a']--;

    ++delta;
    lines[curRow + delta].push_front(lastChar);
    alpaCount[curRow + delta][lastChar - 'a']++;
  }
  ++curCol;
  if (curCol == w) {
    curCol = 0;
    ++curRow;
  }
}

char moveCursor(int mRow, int mCol) {
  int row = mRow - 1;
  int col = mCol - 1;
  if (row * w + col >= wordCnt) {
    int lastRow = wordCnt / w;
    int lastCol = wordCnt % w;
    curRow = lastRow;
    curCol = lastCol;
    return '$';
  } else {
    curCol = col;
    curRow = row;
    return lines[curRow][curCol];
  }
}

int countCharacter(char mChar) {
  int ret = 0;
  for (int col = curCol; col < lines[curRow].size(); ++col) {
    if (lines[curRow][col] == mChar) {
      ret++;
    }
  }
  for (int index = curRow + 1; index < h; ++index) {
    ret += alpaCount[index][mChar - 'a'];
  }
  return ret;
}
