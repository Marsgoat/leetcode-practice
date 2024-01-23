#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // Bit Manipulation
  int maxLength(vector<string>& arr) {
    int result = 0;
    vector<int> masks = {0};

    for (string s : arr) {
      int mask = 0;
      for (char c : s) {
        mask |= 1 << (c - 'a');
      }

      if (__builtin_popcount(mask) != s.size()) continue;

      for (int i = masks.size() - 1; i >= 0; i--) {
        if (mask & masks[i]) continue;
        masks.push_back(mask | masks[i]);
        result = max(result, __builtin_popcount(mask | masks[i]));
      }
    }

    return result;
  }

  // Backtracking
  int maxLength2(vector<string>& arr) {
    int result = 0;
    vector<string> path;
    backtrack(arr, path, 0, result);
    return result;
  }

  void backtrack(vector<string>& arr, vector<string>& path, int index,
                 int& result) {
    if (index == arr.size()) {
      int length = 0;
      for (string s : path) {
        length += s.size();
      }
      result = max(result, length);
      return;
    }

    if (isUnique(arr[index], path)) {
      path.push_back(arr[index]);
      backtrack(arr, path, index + 1, result);
      path.pop_back();
    }

    backtrack(arr, path, index + 1, result);
  }

  bool isUnique(string& s, vector<string>& path) {
    vector<int> frequency(26);
    for (string str : path) {
      for (char c : str) {
        frequency[c - 'a']++;
      }
    }

    for (char c : s) {
      frequency[c - 'a']++;
      if (frequency[c - 'a'] > 1) return false;
    }

    return true;
  }
};

int main() {
  Solution solution;
  vector<string> arr = {"un", "iq", "ue"};
  cout << solution.maxLength(arr) << endl;
  return 0;
}