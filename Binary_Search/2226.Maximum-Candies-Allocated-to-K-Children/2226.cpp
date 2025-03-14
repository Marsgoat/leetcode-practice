#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumCandies(vector<int>& candies, long long k) {
    int n = candies.size();
    int maxCandies = *max_element(candies.begin(), candies.end());
    int minCandies = 0;

    while (minCandies < maxCandies) {
      int mid = minCandies + (maxCandies - minCandies + 1) / 2;
      float allocatedCandies = 0;
      for (int candy : candies) {
        allocatedCandies += candy / mid;
      }

      if (allocatedCandies >= k) {
        minCandies = mid;
      } else {
        maxCandies = mid - 1;
      }
    }

    return minCandies;
  }
};