#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int left = 0;
    int product = 1;
    int count = 0;
    int result = 0;
    for (int num : nums) {
      product *= num;
      count++;
      while (product >= k) {
        product /= nums[left];
        left++;
        count--;
      }
      result += count;
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {10, 5, 2, 6};
  int k = 100;
  cout << solution.numSubarrayProductLessThanK(nums, k) << endl;
  return 0;
}