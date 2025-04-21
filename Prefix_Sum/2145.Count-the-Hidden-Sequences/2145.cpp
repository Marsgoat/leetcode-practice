#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long minValue = 0;
    long long maxValue = 0;
    long long currentValue = 0;

    for (int diff : differences) {
      currentValue += diff;
      minValue = min(minValue, currentValue);
      maxValue = max(maxValue, currentValue);
    }

    return max(0LL, (upper - lower) - (maxValue - minValue) + 1);
  }
};

int main() {
  Solution solution;
  vector<int> differences = {1, -3, 4};
  int lower = 1;
  int upper = 6;
  cout << solution.numberOfArrays(differences, lower, upper) << endl;
  return 0;
}