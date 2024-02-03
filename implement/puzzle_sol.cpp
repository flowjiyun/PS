#include <algorithm>
#include <cstring>
#include <deque>
#include <limits>
#include <utility>
#include <vector>

#define MAX_ROW 40
#define MAX_COL 30

using namespace std;

const int MAX_VAL = numeric_limits<int>::max();

const vector<vector<pair<int, int>>> puzzleType = {
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}},
    {{0, 0}, {0, 1}},
};

// backup data struct
struct Data {
  int type;
  int hash;
  deque<pair<int, int>> posList;
};

struct Result {
  int row;
  int col;
};

deque<pair<int, int>> hashMap[5][1 << 15]; // ok
vector<pair<int, int>> keyList;            // ok
vector<Data> backup;                       // ok

int row, col;                   // ok
bool visited[MAX_ROW][MAX_COL]; // ok

void init(int mRows, int mCols, int mCells[MAX_ROW][MAX_COL]) {
  row = mRows;
  col = mCols;
  memset(visited, 0, sizeof(visited));
  backup.clear();
  for (const auto &[type, hash] : keyList) {
    hashMap[type][hash].clear();
  }
  keyList.clear();

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      for (int type = 0; type < 5; ++type) {
        bool isOk = true;
        int minVal = MAX_VAL;
        for (const auto &[di, dj] : puzzleType[type]) {
          // 보드 범위 체크
          int curRow = i + di;
          int curCol = j + dj;
          if (curRow >= row || curCol >= col) {
            isOk = false;
            break;
          }
          minVal = min(minVal, mCells[curRow][curCol]);
        }
        if (!isOk) {
          continue;
        }
        int hash = 0;
        for (const auto &[di, dj] : puzzleType[type]) {
          int curRow = i + di;
          int curCol = j + dj;
          int delta = mCells[curRow][curCol] - minVal;
          hash <<= 3;
          hash += delta;
        }
        hashMap[type][hash].push_back({i, j});
        keyList.push_back({type, hash});
      }
    }
  }
  // 중복 키 제거
  sort(keyList.begin(), keyList.end());
  auto it = unique(keyList.begin(), keyList.end());
  keyList.resize(distance(keyList.begin(), it));
  for (const auto &[type, hash] : keyList) {
    // 오름 차순으로 정렬
    sort(hashMap[type][hash].begin(), hashMap[type][hash].end());
    // backup data 저장
    backup.push_back({type, hash, hashMap[type][hash]});
  }
}

Result putPuzzle(int mPuzzle[3][3]) {
  // 퍼즐 타입 찾기
  int type = -1;
  int minVal;
  for (int t = 0; t < 5; ++t) {
    bool isOk = true;
    minVal = MAX_VAL;
    for (const auto &[curRow, curCol] : puzzleType[t]) {
      if (mPuzzle[curRow][curCol] == 0) {
        isOk = false;
        break;
      }
      minVal = min(minVal, mPuzzle[curRow][curCol]);
    }
    if (isOk) {
      type = t;
      break;
    }
  }
  // 해쉬 계산 하기
  Result ret = {-1, -1};
  int hash = 0;
  for (const auto &[curRow, curCol] : puzzleType[type]) {
    int delta = mPuzzle[curRow][curCol] - minVal;
    hash <<= 3;
    hash += delta;
  }
  // 우선 순위가 높은 위치 부터 놓을 수 있는지 확인하면서 놓아보기
  auto &posList = hashMap[type][hash];
  while (!posList.empty()) {
    auto [curRow, curCol] = posList.front();
    posList.pop_front();

    // 기존에 한번 놓여졌는지 확인
    bool isOk = true;
    for (const auto &[di, dj] : puzzleType[type]) {
      int nRow = curRow + di;
      int nCol = curCol + dj;
      if (visited[nRow][nCol] == true) {
        isOk = false;
        break;
      }
    }
    if (!isOk) {
      continue;
    }

    // 퍼즐 놓기
    for (const auto &[di, dj] : puzzleType[type]) {
      int nRow = curRow + di;
      int nCol = curCol + dj;
      visited[nRow][nCol] = true;
    }
    ret = {curRow, curCol};
    break;
  }
  return ret;
}

void clearPuzzles() {
  memset(visited, 0, sizeof(visited));
  for (const auto [type, hash, posList] : backup) {
    hashMap[type][hash] = posList;
  }
  return;
}