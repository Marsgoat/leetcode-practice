#include <iostream>

using namespace std;

class Solution {
 public:
  bool halvesAreAlike(string s) {
    int count = 0;
    for (int i = 0; i < s.size() / 2; i++) {
      if (isVowel(s[i])) count++;
      if (isVowel(s[s.size() - 1 - i])) count--;
    }

    return count == 0;
  }

  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
};

int main() {
  Solution solution;
  string s = "book";
  cout << solution.halvesAreAlike(s) << endl;
  return 0;
}