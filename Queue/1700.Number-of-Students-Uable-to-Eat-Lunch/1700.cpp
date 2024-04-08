#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int count = 0;
    while (!students.empty() && !sandwiches.empty()) {
      if (students.front() == sandwiches.front()) {
        count = 0;
        students.erase(students.begin());
        sandwiches.erase(sandwiches.begin());
      } else {
        count++;
        students.push_back(students.front());
        students.erase(students.begin());
      }

      if (count == students.size()) break;
    }

    return students.size();
  }
};

int main() {
  Solution solution;
  vector<int> students = {1, 1, 0, 0};
  vector<int> sandwiches = {0, 1, 0, 1};
  cout << solution.countStudents(students, sandwiches) << endl;
  return 0;
}