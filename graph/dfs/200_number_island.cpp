class Solution {
public:
    int dy[4] = {1, 0, 0, -1};
    int dx[4] = {0, 1, -1, 0};
    vector<vector<int>> visited;
    vector<vector<char>> mGrid;
    int mRowLen;
    int mColLen;

    int numIslands(vector<vector<char>>& grid) {
        mRowLen = grid.size();
        mColLen = grid[0].size();
        int ans = 0;
        mGrid = grid;
        visited = vector(mRowLen, vector(mColLen, 0));

        for (int i = 0; i < mRowLen; ++i) {
            for (int j = 0; j < mColLen; ++j) {
                if (!visited[i][j] && mGrid[i][j] == '1') {
                    visited[i][j] = 1;
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(int row, int col) {
        for (int dir = 0; dir < 4; ++dir) {
            int ny = row + dy[dir];
            int nx = col + dx[dir];
            if (ny < 0 || ny >= mRowLen || nx < 0 || nx >= mColLen) {
                continue;
            } 
            if (visited[ny][nx] == 1 || mGrid[row][col] == '0') {
                continue;
            }
            visited[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
};