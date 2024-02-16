#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> frequency;
    for (auto num : arr) {
      frequency[num]++;
    }

    vector<int> v;
    for (auto p : frequency) {
      v.push_back(p.second);
    }

    sort(v.begin(), v.end());

    int result = v.size();
    for (auto num : v) {
      if (k >= num) {
        k -= num;
        result--;
      } else {
        break;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> arr = {5, 5, 4};
  int k = 1;
  cout << solution.findLeastNumOfUniqueInts(arr, k) << endl;
  arr = {4, 3, 1, 1, 3, 3, 2};
  k = 3;
  cout << solution.findLeastNumOfUniqueInts(arr, k) << endl;
}