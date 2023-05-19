#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int rotateType[4][3][2] = {
  {{0, 0}, {0, 1}, {1, 1}},
  {{0, 0}, {1, 0}, {1, 1}},
  {{0, 0}, {1, 0}, {1, -1}},
  {{0, 0}, {1, 0}, {0, 1}}
};
bool set(vector<vector<int> > &board, int y, int x, int rotate, int delta) {
  bool ok = true;
  for (int i = 0; i < 3; ++i) {
    int ny = y + rotateType[rotate][i][0];
    int nx = x + rotateType[rotate][i][1];
    if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
      ok = false;
      continue;
    }
    if ((board[ny][nx] += delta) > 1) {
      ok = false;
      continue;
    }
  } 
  return ok;
}

int coverBoard(vector<vector<int> > &board) {
  // 왼쪽 위부터 채우기
  int y, x;
  y = -1;
  x = -1;
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      if (board[i][j] == 0) {
        y = i;
        x= j;
        break;
      }
    }
    if (y != -1) {
      break;
    }
  }
  if (y == -1) {
    return 1;
  }
  int ret = 0;
  for (int rotate = 0; rotate < 4; ++rotate) {
      if (set(board, y, x, rotate, 1)) {
        ret += coverBoard(board);
      }
      set(board, y, x, rotate, -1);
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int> > board_int(h, vector<int>(w, 0));
  for (int i = 0; i < h; ++i) {
    string val;
    cin >> val;
    for (int j = 0; j < w; ++j) {
      if (val[j] == '#') {
        board_int[i][j] = 1;
      }
      else {
        board_int[i][j] = 0;
      }
    }
  }
  cout << coverBoard(board_int);
  return 0;
}