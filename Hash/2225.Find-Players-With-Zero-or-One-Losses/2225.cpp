#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<vector<int>> result;
    map<int, int> loses;
    for (auto match : matches) {
      int winner = match[0];
      int loser = match[1];
      if (!loses.count(winner)) loses[winner] = 0;
      loses[loser]++;
    }

    vector<int> zero, ones;

    for (auto [key, value] : loses) {
      if (value == 0) zero.push_back(key);
      if (value == 1) ones.push_back(key);
    }

    return {zero, ones};
  }
};

int main() {
  Solution solution;
  vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6},  {5, 7},
                                 {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
  vector<vector<int>> result = solution.findWinners(matches);
  for (auto row : result) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << endl;
  }

  return 0;
}