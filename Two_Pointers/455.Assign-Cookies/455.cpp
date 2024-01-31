#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int result = 0;
    int left = 0;
    for (int i = 0; i < g.size(); i++) {
      while (left < s.size() && s[left] < g[i]) {
        left++;
      }

      if (left < s.size()) {
        result++;
        left++;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> g = {1, 2, 3};
  vector<int> s = {1, 1};
  cout << solution.findContentChildren(g, s) << endl;
}