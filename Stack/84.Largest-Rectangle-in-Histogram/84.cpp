#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n);
    vector<int> right(n, n);
    vector<int> stack;

    for (int i = 0; i < n; i++) {
      while (!stack.empty() && heights[stack.back()] >= heights[i]) {
        right[stack.back()] = i;
        stack.pop_back();
      }

      left[i] = stack.empty() ? -1 : stack.back();
      stack.push_back(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
      maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
    }

    return maxArea;
  }
};

int main() {
  Solution solution;
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  cout << solution.largestRectangleArea(heights) << endl;
  return 0;
}