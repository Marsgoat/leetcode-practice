#include <iostream>

using namespace std;

class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    int left = 0;
    int cost = 0;
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++) {
      cost += abs(s[i] - t[i]);
      while (cost > maxCost) {
        cost -= abs(s[left] - t[left]);
        left++;
      }
      maxLen = max(maxLen, i - left + 1);
    }

    return maxLen;
  }
};

int main() {
  Solution solution;
  string s = "abcd";
  string t = "bcdf";
  int maxCost = 3;
  cout << solution.equalSubstring(s, t, maxCost) << endl;
  return 0;
}