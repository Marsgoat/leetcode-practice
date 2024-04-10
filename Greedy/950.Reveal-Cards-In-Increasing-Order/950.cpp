#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    vector<int> order(deck.size());
    sort(deck.begin(), deck.end());
    for (int i = 0; i < deck.size(); i++) {
      order[i] = i;
    }

    vector<int> result(deck.size());
    int i = 0;
    while (order.size() > 0) {
      result[order[0]] = deck[i];
      order.erase(order.begin());
      if (order.size() > 0) {
        order.push_back(order[0]);
        order.erase(order.begin());
      }
      i++;
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
  vector<int> result = solution.deckRevealedIncreasing(deck);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}