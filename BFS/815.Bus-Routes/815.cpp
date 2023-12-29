#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    if (source == target) return 0;

    unordered_map<int, vector<int>> stopToBuses;
    for (int i = 0; i < routes.size(); i++) {
      for (int stop : routes[i]) {
        stopToBuses[stop].push_back(i);
      }
    }

    // BFS
    queue<int> q;
    unordered_set<int> visitedStops;
    unordered_set<int> visitedBuses;
    for (int bus : stopToBuses[source]) {
      q.push(bus);
      visitedBuses.insert(bus);
    }

    int steps = 1;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int bus = q.front();
        q.pop();

        for (int stop : routes[bus]) {
          if (stop == target) return steps;

          if (!visitedStops.insert(stop).second) continue;

          for (int nextBus : stopToBuses[stop]) {
            if (visitedBuses.insert(nextBus).second) {
              q.push(nextBus);
            }
          }
        }
      }

      steps++;
    }

    return -1;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
  int source = 1, target = 6;
  cout << solution.numBusesToDestination(routes, source, target) << endl;
  return 0;
}
