#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<int> frequency(nums.size() + 1);
    vector<vector<int>> result;

    for (int num : nums) {
      if (frequency[num] >= result.size()) {
        result.push_back(vector<int>());
      }

      result[frequency[num]].push_back(num);
      frequency[num]++;
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 1, 2, 3, 3};
  vector<vector<int>> result = solution.findMatrix(nums);
  for (auto row : result) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}