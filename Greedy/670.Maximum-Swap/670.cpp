#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumSwap(int num) {
    string numStr = to_string(num);
    int n = numStr.size();
    vector<int> lastIdx(10, -1);

    for (int i = 0; i < n; i++) {
      lastIdx[numStr[i] - '0'] = i;
    }

    for (int i = 0; i < n; i++) {
      for (int d = 9; d > numStr[i] - '0'; d--) {
        if (lastIdx[d] > i) {
          swap(numStr[i], numStr[lastIdx[d]]);
          return stoi(numStr);
        }
      }
    }

    return num;
  }
};

int main() {
  Solution s;
  cout << s.maximumSwap(2736) << endl;
  return 0;
}