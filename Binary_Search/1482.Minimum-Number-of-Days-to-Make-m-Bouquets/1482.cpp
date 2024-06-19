#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    if ((long long)m * k > bloomDay.size()) return -1;

    int left = INT_MAX;
    int right = INT_MIN;
    for (int day : bloomDay) {
      left = min(left, day);
      right = max(right, day);
    }

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (canMake(bloomDay, m, k, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

 private:
  bool canMake(vector<int>& bloomDay, int m, int k, int day) {
    int bouquets = 0;
    int flowers = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
      if (bloomDay[i] <= day) {
        flowers++;
        if (flowers == k) {
          bouquets++;
          flowers = 0;
        }
      } else {
        flowers = 0;
      }
    }

    return bouquets >= m;
  }
};

int main() {
  Solution solution;
  vector<int> bloomDay = {1, 10, 3, 10, 2};
  int m = 3, k = 1;
  cout << solution.minDays(bloomDay, m, k) << endl;
  return 0;
}