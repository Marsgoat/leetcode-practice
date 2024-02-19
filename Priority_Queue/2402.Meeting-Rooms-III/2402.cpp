#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<int> meetingCount(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        usedRooms;

    priority_queue<int, vector<int>, greater<int>> availableRooms;

    for (int i = 0; i < n; i++) {
      availableRooms.push(i);
    }
    sort(meetings.begin(), meetings.end());

    for (auto meeting : meetings) {
      while (!usedRooms.empty() && usedRooms.top().first <= meeting[0]) {
        availableRooms.push(usedRooms.top().second);
        usedRooms.pop();
      }

      if (!availableRooms.empty()) {
        int room = availableRooms.top();
        availableRooms.pop();
        usedRooms.push({meeting[1], room});
        meetingCount[room]++;
      } else {
        auto [end, room] = usedRooms.top();
        usedRooms.pop();
        usedRooms.push({end + meeting[1] - meeting[0], room});
        meetingCount[room]++;
      }
    }

    int maxMeetingCount = 0;
    int maxMeetingRoom = 0;
    for (int i = 0; i < n; i++) {
      if (meetingCount[i] > maxMeetingCount) {
        maxMeetingCount = meetingCount[i];
        maxMeetingRoom = i;
      }
    }

    return maxMeetingRoom;
  }
};

int main() {
  Solution solution;
  int n = 2;
  vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
  cout << solution.mostBooked(n, meetings) << endl;
}