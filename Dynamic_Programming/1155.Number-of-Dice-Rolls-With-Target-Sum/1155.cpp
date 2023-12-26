#include <iostream>

using namespace std;

class Solution {
 public:
  int numRollsToTarget(int n, int k, int target) {
    const int MOD = 1e9 + 7;
    int dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= target; j++) {
        for (int l = 1; l <= k; l++) {
          if (j >= l) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
          }
        }
      }
    }

    return dp[n][target];
  }
};

int main() {
  Solution solution;
  int n = 2, k = 6, target = 7;
  cout << solution.numRollsToTarget(n, k, target) << endl;
  return 0;
}