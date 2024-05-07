#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int result = 0;

    for (int price : prices) {
      if (price > minPrice) {
        result += price - minPrice;
        minPrice = price;
      } else {
        minPrice = min(minPrice, price);
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << solution.maxProfit(prices) << endl;
  return 0;
}