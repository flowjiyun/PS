class Solution {
public:
    vector<int> nums_;
    vector<int> memo_;
    int lengthOfLIS(vector<int>& nums) {
        nums_ = nums;
        memo_ = vector(nums.size(), -1);
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans = max(ans, dp(i));
        }
        return ans;
    }

    int dp(int i) {
        if (memo_[i] != -1) {
            return memo_[i];
        }
        int ans = 1;
        for (int j = 0; j < i; ++j) {
            if (nums_[j] < nums_[i]) {
                ans = max(ans, dp(j) + 1);
            }
        }
        memo_[i] = ans;
        return ans;
    }
}