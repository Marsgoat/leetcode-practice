#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    long long left = 0;
    long long right = 1LL * *max_element(time.begin(), time.end()) * totalTrips;

    while (left < right) {
      long long mid = left + (right - left) / 2;
      if (canTrip(time, totalTrips, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

  bool canTrip(vector<int>& time, int totalTrips, long long mid) {
    long long trips = 0;
    for (int t : time) {
      trips += mid / t;
    }
    return trips >= totalTrips;
  }
};

int main() {
  Solution solution;
  vector<int> time = {1, 2, 3};
  int totalTrips = 5;
  cout << solution.minimumTime(time, totalTrips) << endl;
  return 0;
}