#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // O(n^2) brute force
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (j != i) {
          result[i] *= nums[j];
        }
      }
    }

    return result;
  }

  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    vector<int> prefixProduct(nums.size(), 1);
    vector<int> suffixProduct(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
      prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
      suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < nums.size(); i++) {
      result[i] = prefixProduct[i] * suffixProduct[i];
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> result = solution.productExceptSelf(nums);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}