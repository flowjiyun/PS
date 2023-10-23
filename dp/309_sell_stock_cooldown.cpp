class Solution {
public:
    vector<int> prices_;
    vector<vector<int>> memo_;
    int maxProfit(vector<int>& prices) {
        prices_ = prices;
        memo_ = vector(prices_.size(), vector(2, -1));
        return dp(0, 0); 
    }

    int dp(int i, int hasStock) {
        if (i >= prices_.size()) {
            return 0;
        }
        if (memo_[i][hasStock] != -1) {
            return memo_[i][hasStock];
        }
        int ans = dp(i + 1, hasStock);
        if (hasStock == 1) {
            ans = max(ans, prices_[i] + dp(i + 2, 0));
        } else {
            ans = max(ans, -prices_[i] + dp(i + 1, 1));
        }
        memo_[i][hasStock] = ans;
        return ans;
    }
};