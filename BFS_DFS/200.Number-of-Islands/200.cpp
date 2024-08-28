#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    if (grid.empty()) {
      return result;
    }

    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == '1') {
          result++;
          grid[i][j] = '0';
          queue<pair<int, int>> q;
          q.push({i, j});

          while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            for (vector<int> direction : directions) {
              int newRow = current.first + direction[0];
              int newCol = current.second + direction[1];

              if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                  newCol < cols && grid[newRow][newCol] == '1') {
                grid[newRow][newCol] = '0';
                q.push({newRow, newCol});
              }
            }
          }
        }
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};
  cout << solution.numIslands(grid) << endl;
  return 0;
}