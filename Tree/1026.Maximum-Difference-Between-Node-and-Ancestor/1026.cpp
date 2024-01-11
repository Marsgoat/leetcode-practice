#include <iostream>

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
  int maxAncestorDiff(TreeNode* root) {
    return traverse(root, root->val, root->val);
  }

  int traverse(TreeNode* root, int minVal, int maxVal) {
    if (root == nullptr) return maxVal - minVal;
    minVal = min(minVal, root->val);
    maxVal = max(maxVal, root->val);
    return max(traverse(root->left, minVal, maxVal),
               traverse(root->right, minVal, maxVal));
  }

  // 吉神分享的解法 使用alpha beta pruning
  int maxAncestorDiff2(TreeNode* root, int alpha = INT_MAX,
                       int beta = INT_MIN) {
    if (root == nullptr) return 0;
    alpha = min(alpha, root->val);
    beta = max(beta, root->val);
    return root->left == root->right
               ? beta - alpha
               : max(maxAncestorDiff2(root->left, alpha, beta),
                     maxAncestorDiff2(root->right, alpha, beta));
  }
};

int main() {
  Solution solution;
  TreeNode* root = new TreeNode(8);
  root->left = new TreeNode(3);
  root->right = new TreeNode(10);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(6);
  root->left->right->left = new TreeNode(4);
  root->left->right->right = new TreeNode(7);
  root->right->right = new TreeNode(14);
  root->right->right->left = new TreeNode(13);
  cout << solution.maxAncestorDiff(root) << endl;
  return 0;
}