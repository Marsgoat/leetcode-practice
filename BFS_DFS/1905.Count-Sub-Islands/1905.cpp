#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid1.size();
    int n = grid1[0].size();
    int count = 0;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid2[i][j] == 1) {
          if (dfs(grid1, grid2, directions, i, j, m, n)) {
            count++;
          }
        }
      }
    }

    return count;
  }

 private:
  bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
           vector<vector<int>>& directions, int x, int y, int m, int n) {
    if (x < 0 || x >= m || y < 0 || y >= n || grid2[x][y] == 0) {
      return true;
    }

    grid2[x][y] = 0;

    bool isSubIsland = grid1[x][y] == 1;

    for (auto& direction : directions) {
      int nx = x + direction[0];
      int ny = y + direction[1];
      if (!dfs(grid1, grid2, directions, nx, ny, m, n)) {
        isSubIsland = false;
      }
    }

    return isSubIsland;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> grid1 = {{1, 1, 1, 1, 0, 0},
                               {0, 1, 1, 1, 1, 1},
                               {0, 0, 0, 1, 1, 1},
                               {1, 0, 0, 1, 1, 0},
                               {1, 1, 0, 1, 0, 1}};
  vector<vector<int>> grid2 = {{1, 1, 1, 1, 0, 0},
                               {0, 0, 1, 1, 1, 1},
                               {0, 0, 0, 1, 1, 1},
                               {1, 0, 0, 1, 1, 0},
                               {1, 1, 0, 1, 0, 1}};
  cout << solution.countSubIslands(grid1, grid2) << endl;
  return 0;
}