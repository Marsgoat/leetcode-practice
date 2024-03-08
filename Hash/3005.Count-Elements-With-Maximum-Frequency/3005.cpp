#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> freq;
    int maxFreq = 1;
    int count = 0;
    for (int num : nums) {
      freq[num]++;
    }

    for (auto& [num, f] : freq) {
      if (freq[num] > maxFreq) {
        count = 1;
        maxFreq = freq[num];
      } else if (freq[num] == maxFreq) {
        count++;
      }
    }

    return count * maxFreq;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 2, 3, 1, 4};
  cout << solution.maxFrequencyElements(nums) << endl;
  return 0;
}