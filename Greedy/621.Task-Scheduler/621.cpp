#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);
    for (char task : tasks) {
      count[task - 'A']++;
    }

    sort(count.begin(), count.end(), greater<int>());

    int maxCount = count[0];
    int maxCountTasks = 0;

    for (int i = 0; i < 26; i++) {
      if (count[i] == maxCount) {
        maxCountTasks++;
      }
    }

    return max((maxCount - 1) * (n + 1) + maxCountTasks, (int)tasks.size());
  }
};

int main() {
  Solution solution;
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;
  cout << solution.leastInterval(tasks, n) << endl;
  return 0;
}