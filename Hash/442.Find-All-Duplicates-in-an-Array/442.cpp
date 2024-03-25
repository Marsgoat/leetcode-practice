#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates;
    unordered_map<int, int> map;
    for (int num : nums) {
      if (!map[num]) {
        map[num] = 1;
      } else {
        duplicates.push_back(num);
      }
    }

    return duplicates;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> result = solution.findDuplicates(nums);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}