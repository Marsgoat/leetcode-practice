#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int matrixScore(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int result = rows * (1 << (cols - 1));

    for (int j = 1; j < cols; j++) {
      int count = 0;

      for (int i = 0; i < rows; i++) {
        count += grid[i][j] == grid[i][0] ? 1 : 0;
      }
      result += max(count, rows - count) * (1 << (cols - j - 1));
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> grid = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
  cout << solution.matrixScore(grid) << endl;
  return 0;
}