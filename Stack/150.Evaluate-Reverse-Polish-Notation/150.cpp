#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    unordered_map<string, function<int(int, int)>> operators = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }}};

    for (string token : tokens) {
      if (operators.count(token)) {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        s.push(operators[token](a, b));
      } else {
        s.push(stoi(token));
      }
    }

    return s.top();
  }
};

int main() {
  Solution solution;
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  cout << solution.evalRPN(tokens) << endl;
  return 0;
}