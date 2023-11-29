#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int row, col;
// 8방향 움직임
int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

vector<vector<int>> map;
vector<vector<int>> ball;
// 해당 칸의 공이 최종적으로 갈 위치
vector<vector<pair<int, int>>> memo;

pair<int, int> dp(int y, int x) {
    pair<int, int>& pos  = memo[y][x];

    if (pos.first != -1) {
        return pos;
    }

    int curMinVal = 300001;
    int curMinDir = -1;
    for (int dir = 0 ; dir < 9; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= row || nx < 0 || nx >= col) {
            continue;
        }
        if (curMinVal > map[ny][nx]) {
            curMinVal = map[ny][nx];
            curMinDir = dir;
        }
    }
    // 최소 값의 위치가 자기 자신일때 갈 곳
    if (curMinDir== 4) {
        pos.first = y;
        pos.second = x;
        return pos;
    } else {
        pos = dp(y + dy[curMinDir], x + dx[curMinDir]);
        return pos;
    } 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> row >> col;
    map = vector(row, vector(col, 0));
    ball = vector(row, vector(col, 0));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> map[i][j];
        }
    }

    memo = vector(row, vector(col, make_pair(-1, -1)));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            ball[dp(i, j).first][dp(i, j).second]++;
        }
    }
    for (auto row : ball) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}