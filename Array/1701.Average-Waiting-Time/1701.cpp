#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double result = 0;
    int time = 0;
    for (auto customer : customers) {
      if (time < customer[0]) {
        time = customer[0];
      }

      time += customer[1];
      result += time - customer[0];
    }

    return result / customers.size();
  }
};

int main() {
  Solution solution;
  vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
  cout << solution.averageWaitingTime(customers) << endl;
  return 0;
}