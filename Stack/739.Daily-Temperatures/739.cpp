#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
      while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
        int index = s.top();
        s.pop();
        result[index] = i - index;
      }
      s.push(i);
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> result = solution.dailyTemperatures(temperatures);
  for (int i : result) {
    cout << i << " ";
  }
  cout << endl;
}