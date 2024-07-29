#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numTeams(vector<int>& rating) {
    int n = rating.size();
    int teams = 0;

    for (int i = 0; i < n; i++) {
      int leftSmaller = 0;
      int rightLarger = 0;

      for (int j = i - 1; j >= 0; j--) {
        if (rating[j] < rating[i]) {
          leftSmaller++;
        }
      }

      for (int j = i + 1; j < n; j++) {
        if (rating[j] > rating[i]) {
          rightLarger++;
        }
      }

      teams += leftSmaller * rightLarger;

      int leftLarger = i - leftSmaller;
      int rightSmaller = n - i - 1 - rightLarger;

      teams += leftLarger * rightSmaller;
    }

    return teams;
  }
};

int main() {
  Solution solution;
  vector<int> rating = {2, 5, 3, 4, 1};
  cout << solution.numTeams(rating) << endl;
  return 0;
}