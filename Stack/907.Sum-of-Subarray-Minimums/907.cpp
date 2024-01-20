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
      while (arr[Stack.top()] > arr[i]) {
        nextSmaller[Stack.top()] = i;
        Stack.pop();
      }

      Stack.push(i);
    }

    while (!Stack.empty()) Stack.pop();

    for (int i = n - 1; i >= 0; i++) {
      while (arr[Stack.top()] >= arr[i]) {
        prevSmaller[Stack.top()] = i;
        Stack.pop();
      }

      Stack.push(i);
    }

    long long result = 0;
    long long MOD = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      int a = prevSmaller[i];
      int b = nextSmaller[i];
      long num = arr[i] * (i - a) % MOD * (b - i) % MOD;
      result = (result + num) % MOD;
    }

    return result;
  }
};