#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int result = 1;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          result = max(result, dp[i]);
        }
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << solution.lengthOfLIS(nums) << endl;
  return 0;
}