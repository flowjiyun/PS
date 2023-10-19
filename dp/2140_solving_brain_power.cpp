class Solution {
public:
    vector<vector<int>> questions_;
    vector<long long> memo_;
    long long mostPoints(vector<vector<int>>& questions) {
       questions_ = questions;
       memo_ = vector(questions.size(), (long long)-1);
       return dp(0); 
    }

    long long dp(int i) {
        if (i >= questions_.size()) {
            return 0;
        }
        if (memo_[i] != -1) {
            return memo_[i];
        }
        int j = i + questions_[i][1] + 1;
        memo_[i] = max(dp(j) + questions_[i][0], dp(i + 1));
        return memo_[i];
    }
}
