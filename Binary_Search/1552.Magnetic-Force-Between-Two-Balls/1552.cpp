#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int left = 1;
    int right = position.back() - position.front() + 1;

    while (right > left) {
      int mid = (right + left) / 2;
      if (!check(position, m, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left - 1;
  }

  bool check(vector<int>& position, int m, int mid) {
    int count = 1;
    int prev = position[0];
    for (int i = 1; i < position.size(); i++) {
      if (position[i] - prev >= mid) {
        count++;
        prev = position[i];
        if (count >= m) return true;
      }
    }

    return false;
  }
};

int main() {
  Solution solution;
  vector<int> position = {1, 2, 3, 4, 7};
  int m = 3;
  cout << solution.maxDistance(position, m) << endl;
  return 0;
}