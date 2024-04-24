#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int sum = 0;
    int minLen = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      while (sum >= target) {
        minLen = min(minLen, i - left + 1);
        sum -= nums[left];
        left++;
      }
    }

    return minLen == INT_MAX ? 0 : minLen;
  }
};

int main() {
  Solution solution;
  int target = 7;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  cout << solution.minSubArrayLen(target, nums) << endl;
  return 0;
}