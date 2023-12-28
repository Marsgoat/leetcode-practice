#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int max = *max_element(piles.begin(), piles.end());
    int min = 1;

    while (max > min) {
      int mid = min + (max - min) / 2;
      if (canEat(piles, h, mid)) {
        max = mid;
      } else {
        min = mid + 1;
      }
    }

    return min;
  }

  bool canEat(vector<int>& piles, int h, int mid) {
    int count = 0;
    for (int pile : piles) {
      count += ceil(pile * 1.0 / mid);
    }

    return count <= h;
  }
};

int main() {
  Solution solution;
  vector<int> piles = {3, 6, 7, 11};
  int h = 8;
  cout << solution.minEatingSpeed(piles, h) << endl;
  return 0;
}