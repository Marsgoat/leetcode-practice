#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
      left >>= 1;
      right >>= 1;
      shift++;
    }

    return left << shift;
  }
};

int main() {
  Solution solution;
  int left = 5, right = 7;
  cout << solution.rangeBitwiseAnd(left, right) << endl;
  left = 0, right = 0;
  cout << solution.rangeBitwiseAnd(left, right) << endl;
  left = 1, right = 2147483647;
  cout << solution.rangeBitwiseAnd(left, right) << endl;
  return 0;
}