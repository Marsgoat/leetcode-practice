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
  int sumNumbers(TreeNode* root) { return sumNodes(root, 0); }
  int sumNodes(TreeNode* root, int currentSum) {
    if (root == NULL) return 0;
    currentSum = currentSum * 10 + root->val;
    if (root->left == NULL && root->right == NULL) return currentSum;

    int leftSum = sumNodes(root->left, currentSum);
    int rightSum = sumNodes(root->right, currentSum);
    return leftSum + rightSum;
  }
};

int main() {
  Solution solution;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << solution.sumNumbers(root) << endl;
  return 0;
}