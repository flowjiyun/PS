class Solution {
public:
    vector<int> prices_;
    vector<vector<vector<int>>> memo_;
    int maxProfit(int k, vector<int>& prices) {
        prices_ = prices;
        memo_ = vector(prices_.size(), vector(k + 1, vector(2, -1)));
        return dp(0, k, 0);
    }

    int dp(int i, int k, int hasStock) {
        if (i == prices_.size() || k == 0) {
            return 0;
        }
        if (memo_[i][k][hasStock] != -1) {
            return memo_[i][k][hasStock];
        }
        // when skip
        int ans = dp(i + 1, k, hasStock);
        if (hasStock == 1) {
            // two choise
            // skip or sell
            ans = max(ans, prices_[i] + dp(i + 1, k - 1, 0));
        } else if (hasStock == 0) {
            //two choise
            // skip or buy
            ans = max(ans, -prices_[i] + dp(i + 1, k, 1));
        }
        memo_[i][k][hasStock] = ans;
        return ans;
    }
}