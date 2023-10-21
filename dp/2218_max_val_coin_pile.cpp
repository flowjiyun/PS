class Solution {
public:
    vector<vector<int>> piles_;
    vector<vector<int>> memo_;
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        piles_ = piles;
        memo_ = vector(piles.size(), vector(k + 1, -1));
        return dp(0, k);
    }

    int dp(int i, int k) {
        if (i == piles_.size() || k == 0) {
            return 0;
        }
        if (memo_[i][k] != -1) {
            return memo_[i][k];
        }
        // when skip pile
        int ans = dp(i + 1, k);
        int curVal = 0;
        int pileSize = piles_[i].size();

        for (int j = 0; j < min(k, pileSize); ++j) {
            curVal += piles_[i][j];
            // two choice
            // skip curPile or select top of curPile
            ans = max(ans, curVal + dp(i + 1, k - j - 1));
        }
        memo_[i][k] = ans;
        return ans;
    }
};