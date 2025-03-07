#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> closestPrimes(int left, int right) {
    int upper = right;
    vector<int> sieveArray = sieve(upper);
    vector<int> primes;

    for (int i = left; i <= right; i++) {
      if (sieveArray[i] == 1) {
        primes.push_back(i);
      }
    }

    if (primes.size() == 1) {
      return vector<int>{-1, -1};
    }

    int minDiff = INT_MAX;
    vector<int> result(2, -1);

    for (int i = 1; i < primes.size(); i++) {
      int diff = primes[i] - primes[i - 1];
      if (diff < minDiff) {
        minDiff = diff;
        result[0] = primes[i - 1];
        result[1] = primes[i];
      }
    }

    return result;
  }

  vector<int> sieve(int upper) {
    vector<int> sieve(upper + 1, 1);
    sieve[0] = 0;
    sieve[1] = 0;

    for (int i = 2; i * i <= upper; i++) {
      if (sieve[i] == 1) {
        for (int j = i * i; j <= upper; j += i) {
          sieve[j] = 0;
        }
      }
    }

    return sieve;
  }
};

int main() {
  Solution solution;
  vector<int> result = solution.closestPrimes(3, 10);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }
  return 0;
}