#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minIncrementForUnique(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int num : nums) {
      count[num]++;
    }

    int result = 0;
    for (int i = 0; i < count.size(); i++) {
      if (count[i] >= 2) {
        count[i + 1] += count[i] - 1;
        result += count[i] - 1;
        count[i] = 1;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 2};
  cout << solution.minIncrementForUnique(nums) << endl;
  return 0;
}