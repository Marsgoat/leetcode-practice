#include <iostream>

using namespace std;

class Solution {
 public:
  int minFlips(int a, int b, int c) {
    return __builtin_popcount(c ^= (a | b)) + __builtin_popcount(a & b & c);
  }
};

int main() {
  Solution solution;
  int a = 2, b = 6, c = 5;
  cout << "Minimum flips: " << solution.minFlips(a, b, c) << endl;
  return 0;
}