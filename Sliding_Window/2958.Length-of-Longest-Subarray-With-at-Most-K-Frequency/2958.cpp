#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    int maxLen = 0;
    int left = 0;
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++) {
      freq[nums[i]]++;
      while (freq[nums[i]] > k) {
        freq[nums[left]]--;
        left++;
      }

      maxLen = max(maxLen, i - left + 1);
    }

    return maxLen;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
  int k = 2;
  cout << solution.maxSubarrayLength(nums, k) << endl;
  return 0;
}