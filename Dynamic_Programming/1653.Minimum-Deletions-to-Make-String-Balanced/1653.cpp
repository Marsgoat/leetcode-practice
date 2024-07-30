#include <iostream>

using namespace std;

class Solution {
 public:
  int minimumDeletions(string s) {
    int n = s.size();
    int a = 0;
    int b = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') a++;
    }

    int deletions = a;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        a--;
      } else {
        b++;
      }

      deletions = min(deletions, a + b);
    }

    return deletions;
  }
};

int main() {
  Solution solution;
  string s = "aababbab";
  cout << solution.minimumDeletions(s) << endl;
  return 0;
}