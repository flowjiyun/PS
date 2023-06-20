#include <vector>

using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // make prefix sum
        vector<long> prefix = {nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            prefix.push_back(prefix.back() + nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int left = k;
            int right = nums.size() - 1 - k;
            if (left >= 0 && right <= nums.size() - 1 &&  i >= left && i <= right) {
                long avg_sum = prefix[i + k] - prefix[i - k] + nums[i - k];
                ans.push_back(avg_sum / (2 * k + 1));
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};