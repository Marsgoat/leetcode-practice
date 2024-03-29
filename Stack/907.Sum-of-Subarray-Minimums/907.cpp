#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> nextSmaller(n, n);
    vector<int> prevSmaller(n, -1);

    stack<int> Stack;

    for (int i = 0; i < n; i++) {
      while (!Stack.empty() && arr[Stack.top()] > arr[i]) {
        nextSmaller[Stack.top()] = i;
        Stack.pop();
      }

      if (!Stack.empty()) prevSmaller[i] = Stack.top();
      Stack.push(i);
    }

    long long result = 0;
    long long MOD = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      int a = prevSmaller[i];
      int b = nextSmaller[i];
      long long num = arr[i] * (i - a) % MOD * (b - i) % MOD;
      result = (result + num) % MOD;
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> arr = {3, 1, 2, 4};
  cout << solution.sumSubarrayMins(arr) << endl;
}