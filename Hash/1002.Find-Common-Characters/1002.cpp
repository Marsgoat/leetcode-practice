#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    map<char, int> common;
    for (auto word : words) {
      for (char c : word) {
        common[c]++;
      }
    }

    vector<string> result;
    for (char c = 'a'; c <= 'z'; c++) {
      if (common[c] >= words.size()) {
        int count = common[c] / words.size();
        for (int i = 0; i < count; i++) {
          result.push_back(string(1, c));
        }
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<string> words = {"bella", "label", "roller"};
  vector<string> result = solution.commonChars(words);
  for (string s : result) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}