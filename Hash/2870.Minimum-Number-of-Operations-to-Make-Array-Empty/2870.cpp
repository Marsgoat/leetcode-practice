#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    unordered_map<int, int> frequency;
    for (int num : nums) {
      frequency[num]++;
    }

    int count = 0;
    for (auto [_, value] : frequency) {
      if (value == 1) return -1;
      count += ceil(value * 1.0 / 3);
    }

    return count;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {2, 3, 3, 2, 2, 4, 2, 3, 4};
  cout << solution.minOperations(nums) << endl;
  return 0;
}