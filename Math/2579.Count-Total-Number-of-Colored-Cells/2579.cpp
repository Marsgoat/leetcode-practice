#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long coloredCells(int n) {
    long long sum = 1;
    for (int i = 1; i <= n; i++) {
      sum += (n - i) * 4;
    }

    return sum;
  }

  long long coloredCells2(int n) { return 1l * n * n + 1l * (n - 1) * (n - 1); }
};

int main() {
  Solution solution;
  cout << solution.coloredCells(3) << endl;
  return 0;
}