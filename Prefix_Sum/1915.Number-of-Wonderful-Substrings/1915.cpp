#include <iostream>

using namespace std;

class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    long long count[1024] = {1};
    long long res = 0;
    int mask = 0;

    for (char c : word) {
      mask ^= 1 << (c - 'a');
      res += count[mask];
      for (int i = 0; i < 10; i++) {
        res += count[mask ^ (1 << i)];
      }
      count[mask]++;
    }

    return res;
  }
};

int main() {
  Solution solution;
  string word = "aba";
  cout << solution.wonderfulSubstrings(word) << endl;
  return 0;
}