#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
      ListNode* next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    return prev;
  }

  ListNode* reverseList2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* p = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
  }
};

int main() {
  Solution solution;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << solution.reverseList(head) << endl;
  return 0;
}