#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 1; i < n; i++) {
      int min1 = INT_MAX;
      int min2 = INT_MAX;

      for (int j = 0; j < m; j++) {
        if (grid[i - 1][j] < min1) {
          min2 = min1;
          min1 = grid[i - 1][j];
        } else if (grid[i - 1][j] < min2) {
          min2 = grid[i - 1][j];
        }
      }

      for (int j = 0; j < m; j++) {
        grid[i][j] += grid[i - 1][j] == min1 ? min2 : min1;
      }
    }

    int minPathSum = INT_MAX;
    for (int j = 0; j < m; j++) {
      minPathSum = min(minPathSum, grid[n - 1][j]);
    }

    return minPathSum;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> grid = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  cout << solution.minFallingPathSum(grid) << endl;
  return 0;
}