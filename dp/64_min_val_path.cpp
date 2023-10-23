class Solution {
public:
    vector<vector<int>> grid_;
    vector<vector<int>> memo_;
    int minPathSum(vector<vector<int>>& grid) {
        grid_ = grid;
        int row = grid_.size();
        int col = grid_[0].size();
        memo_ = vector(row, vector(col, -1));
        return dp(row - 1, col - 1);
    }

    int dp(int row, int col) {
        if (row == 0 && col == 0) {
            return grid_[row][col];
        }
        if (row < 0 || col < 0) {
            return INT_MAX;
        }
        if (memo_[row][col] != -1) {
            return memo_[row][col];
        }
        memo_[row][col] = grid_[row][col] + min(dp(row - 1, col), dp(row, col - 1));
        return memo_[row][col];
    }
};