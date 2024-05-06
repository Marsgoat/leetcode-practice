#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int maxMoney = 0;
    int minPrice = prices[0];

    for (int price : prices) {
      minPrice = min(minPrice, price);
      maxMoney = max(maxMoney, price - minPrice);
    }

    return maxMoney;
  }
};

int main() {
  Solution solution;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << solution.maxProfit(prices) << endl;
  return 0;
}