#include <iostream>

using namespace std;

class Solution {
 public:
  int longestIdealString(string s, int k) {
    int dp[26] = {0};
    int maxLen = 1;

    for (char c : s) {
      int idx = c - 'a';
      dp[idx] = dp[idx] + 1;

      for (int i = max(0, idx - k); i <= min(25, idx + k); i++) {
        if (i != idx) {
          dp[idx] = max(dp[idx], dp[i] + 1);
        }

        maxLen = max(maxLen, dp[idx]);
      }
    }

    return maxLen;
  }
};

int main() {
  Solution solution;
  string s = "acfgbd";
  int k = 2;
  cout << solution.longestIdealString(s, k) << endl;
  return 0;
}