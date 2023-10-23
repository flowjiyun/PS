class Solution {
public:
    vector<int> prices_;
    int fee_;
    vector<vector<int>> memo_;
    int maxProfit(vector<int>& prices, int fee) {
        prices_ = prices;
        fee_ = fee;
        memo_ = vector(prices_.size(), vector(2, -1));
        return dp(0, 0);
    }

    int dp(int i, int hasStock) {
        if (i == prices_.size()) {
            return 0;
        }
        if (memo_[i][hasStock] != -1) {
            return memo_[i][hasStock];
        }
        //skip, sell, buy
        int ans = dp(i + 1, hasStock);
        if (hasStock == 1) {
            ans = max(ans, dp(i + 1, 0) + prices_[i]);
        } else if (hasStock == 0) {
            ans = max(ans, dp(i + 1, 1) - prices_[i] - fee_);
        }
        memo_[i][hasStock] = ans;
        return ans;
    }
};