#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> result(2, 0);
    long long diff = 0;
    for (int num : nums) {
      diff ^= num;
    }
    diff &= -diff;
    for (int num : nums) {
      if (num & diff) {
        result[0] ^= num;
      } else {
        result[1] ^= num;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 1, 3, 2, 5};
  vector<int> result = solution.singleNumber(nums);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}