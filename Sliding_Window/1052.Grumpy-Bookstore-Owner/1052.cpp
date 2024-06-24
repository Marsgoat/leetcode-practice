#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int result = 0;
    int right = 0;
    int count = 0;

    for (int i = 0; i < customers.size(); i++) {
      if (grumpy[i] == 0) {
        result += customers[i];
      } else {
        count += customers[i];
      }

      if (i >= minutes) {
        count -= grumpy[i - minutes] * customers[i - minutes];
      }

      right = max(right, count);
    }

    return result + right;
  }
};

int main() {
  Solution solution;
  vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
  vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
  int minutes = 3;
  cout << solution.maxSatisfied(customers, grumpy, minutes) << endl;
  return 0;
}