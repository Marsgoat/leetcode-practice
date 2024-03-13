#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // prefix sum
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* front = new ListNode(0, head);
    ListNode* current = front;

    while (current != nullptr) {
      int prefixSum = 0;
      ListNode* next = current->next;

      while (next != nullptr) {
        prefixSum += next->val;
        if (prefixSum == 0) {
          current->next = next->next;
        }
        next = next->next;
      }

      current = current->next;
    }

    return front->next;
  }

  // prefix sum + hash map
  ListNode* removeZeroSumSublists2(ListNode* head) {
    ListNode* front = new ListNode(0, head);
    ListNode* current = front;
    int prefixSum = 0;
    unordered_map<int, ListNode*> map;

    while (current != nullptr) {
      prefixSum += current->val;
      map[prefixSum] = current;
      current = current->next;
    }

    prefixSum = 0;
    current = front;

    while (current != nullptr) {
      prefixSum += current->val;
      current->next = map[prefixSum]->next;
      current = current->next;
    }

    return front->next;
  }
};

int main() {
  Solution solution;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(-3);
  head->next->next->next->next = new ListNode(1);
  cout << solution.removeZeroSumSublists(head) << endl;
  return 0;
}