#include <iostream>

using namespace std;

class Solution {
 public:
  int appendCharacters(string s, string t) {
    int result = 0;
    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size()) {
      if (s[i] == t[j]) {
        i++;
        j++;
      } else {
        i++;
      }
    }

    if (j == t.size()) return 0;
    return t.size() - j;
  }
};

int main() {
  Solution solution;
  string s = "coaching";
  string t = "coding";
  cout << solution.appendCharacters(s, t) << endl;
  return 0;
}