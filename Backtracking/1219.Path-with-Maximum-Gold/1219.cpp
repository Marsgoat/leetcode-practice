#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMaximumGold(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int maxGold = 0;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] != 0) {
          maxGold = max(maxGold, dfs(grid, i, j, rows, cols));
        }
      }
    }

    return maxGold;
  }

  int dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
      return 0;
    }

    int gold = grid[i][j];
    grid[i][j] = 0;
    int maxGold = 0;

    int right = dfs(grid, i, j + 1, rows, cols);
    int left = dfs(grid, i, j - 1, rows, cols);
    int down = dfs(grid, i + 1, j, rows, cols);
    int up = dfs(grid, i - 1, j, rows, cols);

    grid[i][j] = gold;
    return gold + max({right, left, down, up});
  }
};

int main() {
  Solution solution;
  vector<vector<int>> grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
  cout << solution.getMaximumGold(grid) << endl;
  return 0;
}