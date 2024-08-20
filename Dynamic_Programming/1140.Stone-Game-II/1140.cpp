#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> suffixSum(n, 0);
    suffixSum[n - 1] = piles[n - 1];

    for (int i = n - 2; i >= 0; i--) {
      suffixSum[i] = suffixSum[i + 1] + piles[i];
    }

    return minimax(piles, dp, suffixSum, 0, 1);
  }

  int minimax(vector<int>& piles, vector<vector<int>>& dp,
              vector<int>& suffixSum, int i, int m) {
    if (i == piles.size()) return 0;
    if (2 * m >= piles.size() - i) return suffixSum[i];
    if (dp[i][m] != 0) return dp[i][m];

    int minVal = INT_MAX;
    for (int x = 1; x <= 2 * m; x++) {
      minVal = min(minVal, minimax(piles, dp, suffixSum, i + x, max(m, x)));
    }

    dp[i][m] = suffixSum[i] - minVal;
    return dp[i][m];
  }
};

int main() {
  Solution solution;
  vector<int> piles = {2, 7, 9, 4, 4};
  cout << solution.stoneGameII(piles) << endl;
  return 0;
}