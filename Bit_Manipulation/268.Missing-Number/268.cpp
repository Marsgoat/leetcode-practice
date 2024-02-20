#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int result = n;
    for (int i = 0; i < n; i++) {
      result ^= i ^ nums[i];
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {3, 0, 1};
  cout << solution.missingNumber(nums) << endl;
  nums = {0, 1};
  cout << solution.missingNumber(nums) << endl;
  nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  cout << solution.missingNumber(nums) << endl;
  nums = {0};
  cout << solution.missingNumber(nums) << endl;
  return 0;
}