#include <iostream>

using namespace std;

class Solution {
 public:
  bool canMeasureWater(int x, int y, int target) {
    if (target > x + y) return false;

    if (target == 0 || target == x || target == y || target == x + y) {
      return true;
    }

    auto gcd = [](int a, int b) {
      while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
      }
      return a;
    };

    return target % gcd(x, y) == 0;
  }
};