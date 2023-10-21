class Solution {
public:
    string text1_;
    string text2_;
    int longestCommonSubsequence(string text1, string text2) {
        text1_ = text1;
        text2_ = text2;
        vector<vector<int>> memo(text1.size(), vector(text2.size(), -1));
        return dp(0, 0, memo);
    }

    int dp(int i, int j, vector<vector<int>>& memo) {
        if (i == text1_.size() || j == text2_.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (text1_[i] == text2_[j]) {
            memo[i][j] = 1 + dp(i + 1, j + 1, memo);
        } else {
            memo[i][j] = max(dp(i + 1, j, memo), dp(i, j + 1, memo));
        }
        return memo[i][j];
    }
}