#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(nums, 0, path, result);
    return result;
  }

 private:
  void dfs(vector<int>& nums, int index, vector<int>& path,
           vector<vector<int>>& result) {
    if (index == nums.size()) {
      result.push_back(path);
      return;
    }

    path.push_back(nums[index]);
    dfs(nums, index + 1, path, result);
    path.pop_back();
    dfs(nums, index + 1, path, result);
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> result = solution.subsets(nums);
  for (vector<int> vec : result) {
    for (int num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}