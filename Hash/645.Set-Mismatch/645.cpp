#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    vector<int> mp(nums.size() + 1, 0);
    for (int num : nums) {
      mp[num]++;
    }

    int missing = 0;
    int duplicate = 0;

    for (int i = 1; i <= nums.size(); i++) {
      if (mp[i] == 2) duplicate = i;
      if (mp[i] == 0) missing = i;
    }

    return {duplicate, missing};
  }
};

int main() {
  Solution sln;
  vector<int> nums = {1, 2, 2, 4};
  vector<int> ans = sln.findErrorNums(nums);
  for (int num : ans) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}