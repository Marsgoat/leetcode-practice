#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int result = 0;

    while (left < right) {
      if (height[left] < height[right]) {
        if (height[left] >= leftMax) {
          leftMax = height[left];
        } else {
          result += leftMax - height[left];
        }
        left++;
      } else {
        if (height[right] >= rightMax) {
          rightMax = height[right];
        } else {
          result += rightMax - height[right];
        }
        right--;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << solution.trap(height) << endl;
  return 0;
}