#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    map<string, vector<string>> m;

    for (string str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      m[key].push_back(str);
    }

    for (auto [key, value] : m) {
      result.push_back(value);
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result = solution.groupAnagrams(strs);
  for (vector<string> group : result) {
    for (string s : group) {
      cout << s << " ";
    }
    cout << endl;
  }
}