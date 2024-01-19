#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int minimum = matrix[i - 1][j];
        if (j > 0) minimum = min(minimum, matrix[i - 1][j - 1]);
        if (j + 1 < n) minimum = min(minimum, matrix[i - 1][j + 1]);
        matrix[i][j] += minimum;
      }
    }

    int result = matrix[n - 1][0];
    for (int i = 1; i < n; i++) {
      result = min(result, matrix[n - 1][i]);
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  cout << solution.minFallingPathSum(matrix) << endl;
  return 0;
}