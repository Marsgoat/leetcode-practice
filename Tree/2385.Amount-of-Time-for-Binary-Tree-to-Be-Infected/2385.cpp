#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(0), right(0) {}
  TreeNode(int x) : val(x), left(0), right(0) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int amountOfTime(TreeNode* root, int start) {
    traverse(root, start);
    return maxDistance;
  }

  int maxDistance = 0;
  int traverse(TreeNode* root, int start) {
    int depth = 0;
    if (root == nullptr) return depth;

    int leftDepth = traverse(root->left, start);
    int rightDepth = traverse(root->right, start);

    if (root->val == start) {
      maxDistance = max(leftDepth, rightDepth);
      depth = -1;
    } else if (leftDepth >= 0 && rightDepth >= 0) {
      depth = max(leftDepth, rightDepth) + 1;
    } else {
      int distance = abs(leftDepth) + abs(rightDepth);
      maxDistance = max(maxDistance, distance);
      depth = min(leftDepth, rightDepth) - 1;
    }

    return depth;
  }
};

int main() {
  Solution solution;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(5);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(6);
  root->left->right->left = new TreeNode(9);
  root->left->right->right = new TreeNode(2);
  int start = 3;
  cout << solution.amountOfTime(root, start) << endl;
  return 0;
}
