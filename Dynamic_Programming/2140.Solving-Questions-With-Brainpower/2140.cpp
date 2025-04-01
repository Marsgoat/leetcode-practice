#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
      int points = questions[i][0];
      int brainpower = questions[i][1];

      if (i + brainpower + 1 > n) {
        dp[i] = max(dp[i + 1], (long long)points);
      } else {
        dp[i] = max(dp[i + 1], dp[i + brainpower + 1] + points);
      }
    }

    return dp[0];
  }
};