#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
  }

  // space : O(1)
  int rob2(vector<int>& nums) {
    int prev = 0;
    int curr = 0;
    for (int num : nums) {
      int temp = curr;
      curr = max(curr, prev + num);
      prev = temp;
    }

    return curr;
  }
}

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 1};
  cout << solution.rob(nums) << endl;
}