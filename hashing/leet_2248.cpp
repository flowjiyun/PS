#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<vector<int>> &nums) {
      int appear_cnt = nums.size();
      unordered_map<int, int> count;
      vector<int> ans;
      // for (int i = 0; i < appear_cnt; ++i) {
      //   for (int j = 0; j < nums[i].size(); ++j) {
      //     count[nums[i][j]]++;
      //   }
      // }
      for (vector<int> &arr : nums) {
        for (int x : arr) {
          count[x]++;
        }
      }
      // for (auto it = count.begin(); it != count.end(); ++it) {
      //   if (it->second == appear_cnt) {
      //     ans.push_back(it->second);
      //   }
      // }
      for (auto [key, val] : count) {
        if (val == appear_cnt) {
          ans.push_back(key);
        }
      }
      sort(ans.begin(), ans.end());
      return ans;
    }
};