#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    for (int i = 0; i <= right; i++) {
      if (nums[i] == 0) {
        swap(nums[i], nums[left]);
        left++;
      } else if (nums[i] == 2) {
        swap(nums[i], nums[right]);
        right--;
        i--;
      }
    }
  }

  void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  solution.sortColors(nums);
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}