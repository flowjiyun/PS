#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int blockType[2][2][2] = {
    {{0, 0}, {0, 1}}, 
    {{0, 0}, {1, 0}}
};

vector<vector<int>> board;

bool canCovered(int row, int col, int type, int delta) {
    bool ret = true;
    for (int i = 0; i < 2; ++i) {
        int ny = row + blockType[type][i][0];
        int nx = col + blockType[type][i][1];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            ret = false;
        } else if ((board[ny][nx] += delta) > 1) {
            ret = false;
        }
    }
    return ret;
}

int dfs() {
    //타일 놓을 위치를 찾는다 
    int curRow = -1;
    int curCol = -1;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            if (board[row][col] == 0) {
                curRow = row;
                curCol = col;
                break;
            }
        }
        if (curRow != -1) {
            break;
        }
    }
    // base condition
    // 보드가 모두 덮혔을 때 경우의 수 1개 추가
    if (curRow == -1) {
        return 1;
    }
    // 타일 타입별로 보드 채워 보기
    int ret = 0;
    for (int type = 0; type < 2; ++type) {
        if (canCovered(curRow, curCol, type, 1)) {
            ret += dfs();
        }
        // 타일 빼기
        canCovered(curRow, curCol, type, -1);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    board = vector<vector<int>>(n, vector<int>(m, 0));
    cout << (dfs() % 9901);
    return 0;
}