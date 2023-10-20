class Solution {
public:
    int n_;
    vector<int> memo_;
    int climbStairs(int n) { 
        n_ = n;
        memo_ = vector(n, 0);
        return dp(n - 1);
    }

    int dp(int index) {
        if (index <= 0) {
            return 1;
        }
        if (memo_[index] != 0) {
            return memo_[index];
        }
        memo_[index] = dp(index - 2) + dp(index - 1);
        return memo_[index];
    }
}