#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

int n, m;

int dp(int row, int col, int dir, vector<vector<int>>& space, vector<vector<vector<int>>>& memo) {
    if (row == n - 1) {
        return space[row][col];
    }
    if (row >= n || col >= m || row < 0 || col < 0) {
        return std::numeric_limits<int>::max();
    }
    if (memo[row][col][dir] != -1) {
        return memo[row][col][dir];
    }
    if (dir == 0) {
        memo[row][col][dir] = space[row][col] + min(dp(row + 1, col, 1, space, memo), dp(row + 1, col + 1, 2, space, memo));
    } else if (dir == 1) {
        memo[row][col][dir] = space[row][col] + min(dp(row + 1, col - 1, 0, space, memo), dp(row + 1, col + 1, 2, space, memo));
    } else {
        memo[row][col][dir] = space[row][col] + min(dp(row + 1, col - 1, 0, space, memo), dp(row + 1, col, 1, space, memo));
    }
    return memo[row][col][dir];
}

int getMinFuel(vector<vector<int>>& space, vector<vector<vector<int>>>& memo) {
    int ans = std::numeric_limits<int>::max();
    for (int j = 0; j < m; ++j) { 
        memset(&memo, -1, sizeof(memo));
        for (int dir = 0; dir < 3; ++dir) {
            if ((j != 0 && j != m - 1) || (j == 0 && dir != 0) || (j == m - 1 && dir != 2)) {
                ans = min(ans, dp(0, j, dir, space, memo));
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<vector<int>> space(n, vector(m, 0));
    vector<vector<vector<int>>> memo(n, vector(m, vector(3, -1)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> space[i][j];
        }
    }

    cout << getMinFuel(space, memo);
    return 0;
}