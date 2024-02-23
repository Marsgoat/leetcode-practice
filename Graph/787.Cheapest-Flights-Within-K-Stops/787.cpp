#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
    dp[0][src] = 0;
    for (int i = 1; i <= k + 1; i++) {
      dp[i][src] = 0;
      for (auto flight : flights) {
        int from = flight[0];
        int to = flight[1];
        int cost = flight[2];
        if (dp[i - 1][from] != INT_MAX) {
          dp[i][to] = min(dp[i][to], dp[i - 1][from] + cost);
        }
      }
    }

    return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
  }
};

int main() {
  Solution solution;
  vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int n = 4;
  int src = 0;
  int dst = 3;
  int k = 1;
  cout << solution.findCheapestPrice(n, flights, src, dst, k) << endl;
  return 0;
}