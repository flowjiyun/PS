class Solution {
public:
    vector<int> nums_;
    vector<int> memo_;
    int rob(vector<int>& nums) {
        nums_ = nums;
        memo_ = vector(nums_.size(), -1);
        return dp(nums_.size() - 1);
    }

    int dp(int index) {
        if (index == 0) {
            return nums_[0];
        }
        if (index == 1) {
           return max(nums_[0], nums_[1]);
        }
        if (memo_[index] != -1) {
            return memo_[index];
        }
        // check adjacent & not adjacent
        memo_[index] = max(dp(index - 2) + nums_[index], dp(index - 1));
        return memo_[index];
    }
}