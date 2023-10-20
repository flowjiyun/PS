class Solution {
public:
    int memo[13][10001];
    int coinChange(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));
       int count = getFewestNumCoin(0, coins, amount);
       return (count == INT_MAX - 1) ? -1 : count;
    }
    int getFewestNumCoin(int cur, vector<int>& coins, int amount) {
        if (cur >= coins.size() || amount == 0) {
            return (amount == 0) ? 0 : INT_MAX -1;
        }
        if (memo[cur][amount] != -1) {
            return memo[cur][amount];
        }
        if (coins[cur] > amount) {
            int dontPick = getFewestNumCoin(cur + 1, coins, amount);
            memo[cur][amount] = dontPick;
            return memo[cur][amount];
        } else {
            int dontPick = getFewestNumCoin(cur + 1, coins, amount);
            int pick = 1 + getFewestNumCoin(cur, coins, amount - coins[cur]);
            memo[cur][amount] = min(dontPick, pick);
            return memo[cur][amount];
        }
    }
}