#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int right = tokens.size() - 1;
    int left = 0;
    int score = 0;
    int maxScore = 0;
    while (left <= right) {
      if (power >= tokens[left]) {
        power -= tokens[left];
        score++;
        maxScore = max(maxScore, score);
        left++;
      } else if (score > 0) {
        power += tokens[right];
        score--;
        right--;
      } else {
        break;
      }
    }

    return maxScore;
  }
};

int main() {
  Solution solution;
  vector<int> tokens = {100};
  int power = 50;
  cout << solution.bagOfTokensScore(tokens, power) << endl;
  return 0;
}