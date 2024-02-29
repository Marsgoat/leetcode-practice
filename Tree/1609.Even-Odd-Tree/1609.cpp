#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> queue;
    queue.push(root);
    int level = 0;

    while (!queue.empty()) {
      int size = queue.size();
      int prev = level % 2 == 0 ? 0 : INT_MAX;
      for (int i = 0; i < size; i++) {
        TreeNode* current = queue.front();
        queue.pop();
        if (level % 2 == 0) {
          if (current->val % 2 == 0 || current->val <= prev) {
            return false;
          }
        } else {
          if (current->val % 2 != 0 || current->val >= prev) {
            return false;
          }
        }
        prev = current->val;
        if (current->left != nullptr) {
          queue.push(current->left);
        }
        if (current->right != nullptr) {
          queue.push(current->right);
        }
      }

      level++;
    }

    return true;
  }
};