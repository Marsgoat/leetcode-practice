#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    vector<int> hold(n);
    vector<int> sell(n);
    vector<int> cooldown(n);

    hold[0] = -prices[0];
    sell[0] = 0;
    cooldown[0] = 0;

    for (int i = 1; i < n; i++) {
      hold[i] = max(hold[i - 1], cooldown[i - 1] - prices[i]);
      sell[i] = max(sell[i - 1], hold[i - 1] + prices[i]);
      cooldown[i] = max(cooldown[i - 1], sell[i - 1]);
    }

    return max(sell[n - 1], cooldown[n - 1]);
  }
};

int main() {
  Solution solution;
  vector<int> prices = {1, 2, 3, 0, 2};
  cout << solution.maxProfit(prices) << endl;
}