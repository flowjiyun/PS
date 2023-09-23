#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int r, c, t;
int curStatus[51][51];
int nextSpreadStatus[51][51];
int nextBlewStatus[51][51];
pair<int, int> machinePosUpper;
pair<int, int> machinePosLower;
queue<pair<int, int>> dirtPos;

int getDirtCnt() {
  int ret = 0;
  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      if(curStatus[y][x] != -1) {
        ret += curStatus[y][x];
      }
    }
  }
  return ret;
}

void blewUpper() {
  for (int y = 0; y <= machinePosUpper.first; ++y) {
    for (int x = 0; x < c; ++x) {
      if (y == machinePosUpper.first && x < c - 1) {
        nextBlewStatus[y][x + 1] = nextSpreadStatus[y][x];
      } else if (x == c - 1 && y > 0) {
        nextBlewStatus[y - 1][x] = nextSpreadStatus[y][x];
      } else if (y == 0 && x > 0) {
        nextBlewStatus[y][x - 1] = nextSpreadStatus[y][x];
      } else if (x == 0 && y < machinePosUpper.first) {
        nextBlewStatus[y + 1][x] = nextSpreadStatus[y][x];
      } else {
        nextBlewStatus[y][x] = nextSpreadStatus[y][x];
      }
    }
  }
}

void blewLower() {
  for (int y = machinePosLower.first; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      if (y == machinePosLower.first && x < c - 1) {
        nextBlewStatus[y][x + 1] = nextSpreadStatus[y][x];
      } else if (x == c - 1 && y < r - 1) {
        nextBlewStatus[y + 1][x] = nextSpreadStatus[y][x];
      } else if (y == r - 1 && x > 0) {
        nextBlewStatus[y][x - 1] = nextSpreadStatus[y][x];
      } else if (x == 0 && y > machinePosLower.first) {
        nextBlewStatus[y - 1][x] = nextSpreadStatus[y][x];
      } else {
        nextBlewStatus[y][x] = nextSpreadStatus[y][x];
      }
    }
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c >> t;
  bool checkUpper = true;
  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      cin >> curStatus[y][x];
      if (curStatus[y][x] == -1 && checkUpper == true) {
        machinePosUpper.first = y;
        machinePosUpper.second = x;
        checkUpper = false;
      } else if (curStatus[y][x] == -1 && checkUpper == false) {
        machinePosLower.first = y;
        machinePosLower.second = x;
      }
    }
  }
  //print status
  // for (int y = 0; y < r; ++y) {
  //   for (int x = 0; x < c; ++x) {
  //     cout << curStatus[y][x] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << machinePosUpper.first << ' ' << machinePosUpper.second << '\n';
  // cout << machinePosLower.first << ' ' << machinePosLower.second << '\n';

  while(t--) {
    // update spread
    memset(nextSpreadStatus, 0, sizeof(nextSpreadStatus));
    for (int y = 0; y < r; ++y) {
      for (int x = 0; x < c; ++x) {
        if (curStatus[y][x] != 0 && curStatus[y][x] != -1) {
          dirtPos.push({y, x});
        }
      }
    }

    while (!dirtPos.empty()) {
      auto curDirtPos = dirtPos.front();
      dirtPos.pop();
      int curY = curDirtPos.first;
      int curX = curDirtPos.second;
      int dirtCnt = 0;
      int curAmount = curStatus[curY][curX];
      int spreadAmount = curStatus[curY][curX] / 5;
      for (int dir = 0; dir < 4; ++dir) {
        int ny = curY + dy[dir];
        int nx = curX + dx[dir];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) {
          continue;
        }
        if (curStatus[ny][nx] == -1) {
          continue;
        }
        nextSpreadStatus[ny][nx] += spreadAmount;
        ++dirtCnt;
      }
      nextSpreadStatus[curY][curX] += curAmount - spreadAmount * dirtCnt;
    }
    // cout << "======================" << '\n';
    // for (int y = 0; y < r; ++y) {
    //   for (int x = 0; x < c; ++x) {
    //     cout << nextSpreadStatus[y][x] << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << "======================" << '\n';
    //update blew
    memset(nextBlewStatus, 0, sizeof(nextBlewStatus));
    blewUpper();
    blewLower();
    nextBlewStatus[machinePosUpper.first][machinePosUpper.second] = -1;
    nextBlewStatus[machinePosLower.first][machinePosLower.second] = -1;

    // for (int y = 0; y < r; ++y) {
    //   for (int x = 0; x < c; ++x) {
    //     cout << nextBlewStatus[y][x] << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << "======================" << '\n';
    // update cur
    memcpy(curStatus, nextBlewStatus, sizeof(nextBlewStatus));
  }
  // cout << machinePosUpper.first << ' ' << machinePosUpper.second << '\n';
  // cout << machinePosLower.first << ' ' << machinePosLower.second << '\n';
  cout << getDirtCnt();
  return 0;
}