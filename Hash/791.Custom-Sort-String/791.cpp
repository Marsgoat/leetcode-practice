#include <iostream>

using namespace std;

class Solution {
 public:
  // O(n)
  string customSortString(string order, string s) {
    int count[26] = {0};
    for (char c : s) {
      count[c - 'a']++;
    }

    string result;
    for (char c : order) {
      while (count[c - 'a']-- > 0) {
        result += c;
      }
    }

    for (int i = 0; i < 26; i++) {
      while (count[i]-- > 0) {
        result += i + 'a';
      }
    }

    return result;
  }

  // O(nlogn)
  string customSortString2(string order, string s) {
    sort(s.begin(), s.end(),
         [&](char a, char b) { return order.find(a) < order.find(b); });

    return s;
  }
};

int main() {
  Solution solution;
  cout << solution.customSortString("cba", "abcd") << endl;
  return 0;
}