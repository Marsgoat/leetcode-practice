#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    string result = "";
    unordered_map<char, int> frequency;

    for (char c : s) {
      frequency[c]++;
    }

    vector<pair<char, int>> v(frequency.begin(), frequency.end());
    sort(v.begin(), v.end(), [](pair<char, int>& a, pair<char, int>& b) {
      return a.second > b.second;
    });

    for (auto p : v) {
      result += string(p.second, p.first);
    }

    return result;
  }
};

int main() {
  Solution solution;
  string s = "tree";
  cout << solution.frequencySort(s) << endl;
}