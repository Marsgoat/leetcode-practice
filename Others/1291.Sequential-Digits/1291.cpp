#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> result;

    for (int i = 1; i <= 9; i++) {
      int num = i;
      for (int j = i + 1; j <= 9; j++) {
        num = num * 10 + j;
        if (num <= high && num >= low) result.push_back(num);
      }
    }

    sort(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution solution;
  int low = 100;
  int high = 300;
  vector<int> result = solution.sequentialDigits(low, high);
  for (int i : result) {
    cout << i << " ";
  }
  cout << endl;
}