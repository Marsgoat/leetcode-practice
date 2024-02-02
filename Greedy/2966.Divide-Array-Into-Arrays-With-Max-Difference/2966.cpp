#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i += 3) {
      if (nums[i + 2] - nums[i] > k) {
        return {};
      }
      result.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
  int k = 2;
  vector<vector<int>> result = solution.divideArray(nums, k);
  for (auto& row : result) {
    for (auto& col : row) {
      cout << col << " ";
    }
    cout << endl;
  }
}