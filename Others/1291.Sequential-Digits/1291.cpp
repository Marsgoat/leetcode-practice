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

  // 網友神解 簡單粗暴
  vector<int> sequentialDigits2(int low, int high) {
    vector<int> allNums{
        12,      23,       34,       45,       56,     67,     78,      89,
        123,     234,      345,      456,      567,    678,    789,     1234,
        2345,    3456,     4567,     5678,     6789,   12345,  23456,   34567,
        45678,   56789,    123456,   234567,   345678, 456789, 1234567, 2345678,
        3456789, 12345678, 23456789, 123456789};

    vector<int> result;
    for (int num : allNums) {
      if (num >= low && num <= high) result.push_back(num);
    }

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