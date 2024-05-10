#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int buy1 = prices[0];
    int sell1 = 0;
    int buy2 = INT_MAX;
    int sell2 = 0;

    for (int price : prices) {
      buy1 = min(buy1, price);
      sell1 = max(sell1, price - buy1);
      buy2 = min(buy2, price - sell1);
      sell2 = max(sell2, price - buy2);
    }

    return sell2;
  }
};

int main() {
  Solution solution;
  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  cout << solution.maxProfit(prices) << endl;
  return 0;
}