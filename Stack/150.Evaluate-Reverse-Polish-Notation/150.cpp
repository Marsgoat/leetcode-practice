#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    vector<string> operators = {"+", "-", "*", "/"};

    for (auto token : tokens) {
      if (find(operators.begin(), operators.end(), token) != operators.end()) {
        int num2 = s.top();
        s.pop();
        int num1 = s.top();
        s.pop();
        s.push(calculate(num1, num2, token));
      } else {
        s.push(stoi(token));
      }
    }

    return s.top();
  }

  int calculate(int num1, int num2, string op) {
    if (op == "+") return num1 + num2;
    if (op == "-") return num1 - num2;
    if (op == "*") return num1 * num2;
    if (op == "/") return num1 / num2;
    return 0;
  }
};

int main() {
  Solution solution;
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  cout << solution.evalRPN(tokens) << endl;
  return 0;
}