#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    long long result = 0;
    int maxNum = *max_element(nums.begin(), nums.end());

    int left = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == maxNum) count++;
      while (count >= k) {
        if (nums[left] == maxNum) count--;
        left++;
      }

      result += left;
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 3, 2, 3, 3};
  int k = 2;
  cout << solution.countSubarrays(nums, k) << endl;
  return 0;
}