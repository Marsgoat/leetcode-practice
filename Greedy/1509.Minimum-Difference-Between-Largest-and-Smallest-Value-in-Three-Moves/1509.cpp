#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDifference(vector<int>& nums) {
    if (nums.size() <= 4) return 0;
    sort(nums.begin(), nums.end());

    // 共四種可能
    // 1. 刪除最大的三個數字
    // 2. 刪除最小的三個數字
    // 3. 刪除最大的兩個數字和最小的一個數字
    // 4. 刪除最大的一個數字和最小的兩個數字

    int result = INT_MAX;
    for (int i = 0; i < 4; i++) {
      result = min(result, nums[nums.size() - 4 + i] - nums[i]);
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {5, 3, 2, 4};
  cout << solution.minDifference(nums) << endl;
  return 0;
}