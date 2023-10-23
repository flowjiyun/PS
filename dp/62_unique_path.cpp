class Solution {
public:
    vector<vector<int>> memo_;
    int uniquePaths(int m, int n) {
        memo_ = vector(m, vector(n, -1));
        return dp(m - 1, n - 1); 
   }
   
   int dp(int row, int col) {
       if (row == 0 && col == 0) {
           return 1;
       }
       if (row < 0 || col < 0) {
           return 0;
       }
       if (memo_[row][col] != -1) {
           return memo_[row][col];
       }
       memo_[row][col] = dp(row - 1, col) + dp(row, col - 1);
       return memo_[row][col];
   }
};