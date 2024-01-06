#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    int n = startTime.size();
    vector<vector<int>> jobs;
    for (int i = 0; i < n; i++) {
      jobs.push_back({startTime[i], endTime[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end(),
         [](const vector<int>& a, const vector<int>& b) -> bool {
           return a[1] < b[1];
         });

    vector<int> dp(n);
    dp[0] = jobs[0][2];

    for (int i = 1; i < n; i++) {
      int l = 0, r = i - 1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (jobs[mid][1] <= jobs[i][0]) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }

      if (jobs[l][1] <= jobs[i][0]) {
        dp[i] = max(dp[i - 1], dp[l] + jobs[i][2]);
      } else {
        dp[i] = max(dp[i - 1], jobs[i][2]);
      }
    }

    return dp[n - 1];
  }
};

int main() {
  Solution solution;
  vector<int> startTime = {1, 2, 3, 3};
  vector<int> endTime = {3, 4, 5, 6};
  vector<int> profit = {50, 10, 40, 70};
  cout << solution.jobScheduling(startTime, endTime, profit) << endl;
  return 0;
}