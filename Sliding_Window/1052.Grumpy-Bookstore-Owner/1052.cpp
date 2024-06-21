#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {}
};

int main() {
  Solution solution;
  vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
  vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
  int minutes = 3;
  cout << solution.maxSatisfied(customers, grumpy, minutes) << endl;
  return 0;
}