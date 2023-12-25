#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    long long sum = 0;
    long long max = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (i >= 2 && sum > nums[i]) {
        max = sum + nums[i];
      }

      sum += nums[i];
    }

    return max;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 12, 1, 2, 5, 50, 3};
  cout << solution.largestPerimeter(nums) << endl;
  return 0;
}