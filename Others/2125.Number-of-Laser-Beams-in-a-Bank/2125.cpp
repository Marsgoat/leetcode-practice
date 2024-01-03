#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfBeams(vector<string>& bank) {
    int result = 0;
    int prev = 0;
    for (string s : bank) {
      int count = 0;
      for (char c : s) {
        if (c == '1') count++;
      }

      if (count != 0) {
        result += count * prev;
        prev = count;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<string> bank = {"011001", "000000", "010100", "001000"};
  cout << solution.numberOfBeams(bank) << endl;
  return 0;
}