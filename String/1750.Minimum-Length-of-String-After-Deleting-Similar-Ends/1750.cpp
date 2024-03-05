#include <iostream>

using namespace std;

class Solution {
 public:
  int minimumLength(string s) {
    int left = 0;
    int right = s.length() - 1;
    while (right >= left) {
      if (s[left] != s[right]) return right - left + 1;

      char c = s[left];
      while (left <= right && s[left] == c) {
        right--;
      }
      while (right >= left && s[right] == c) {
        left++;
      }
    }

    return right - left + 1;
  }
};

int main() {
  Solution solution;
  cout << solution.minimumLength("ca") << endl;
  return 0;
}