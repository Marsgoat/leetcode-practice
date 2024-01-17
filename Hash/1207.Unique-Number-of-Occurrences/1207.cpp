#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> frequency;
    for (auto n : arr) {
      frequency[n]++;
    }

    unordered_set<int> freqSet;

    for (auto [key, value] : frequency) {
      if (freqSet.count(value)) return false;
      freqSet.insert(value);
    }

    return true;
  }
};

int main() {
  Solution solution;
  vector<int> arr = {1, 2, 2, 1, 1, 3};
  cout << solution.uniqueOccurrences(arr) << endl;
  return 0;
}