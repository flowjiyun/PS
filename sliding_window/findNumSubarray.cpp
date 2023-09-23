#include <vector>
#include <algorithm>

using namespace std;

int findNumSubarray(vector<int> &nums, int k){
  int left = 0, curr = 0, ans = 0;
  for (int right = 0; right < nums.size(); ++right) {
    curr += nums[right];
    while (curr > k) {
      curr -= nums[left++];
    }
    ans += right -left + 1;
  } 
  return ans;
}