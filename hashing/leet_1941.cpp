#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool areOccurencesEqual(string s) {
      unordered_map<char, int> count;
      for (char c : s) {
        count[c]++;
      }
      // int prev = -1;
      // int ans = true;
      // for (auto [key, val] : count) {
      //   if (prev != -1 && val != prev) {
      //     ans = false;
      //     break;
      //   }
      //   prev = val;
      // }
      // return ans;

      // using unordered_set to check frequency
      // can check if values are all same in count map
      unordered_set<int> frequency;
      for (auto [key, val] : count) {
        frequency.insert(val);
      }
      return (frequency.size() == 1);
    }
};