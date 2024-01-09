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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1, leaves2;
    findLeaves(root1, leaves1);
    findLeaves(root2, leaves2);
    return leaves1 == leaves2;
  }

  int findLeaves(TreeNode* root, vector<int>& leaves) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) {
      leaves.push_back(root->val);
      return 1;
    }
    return findLeaves(root->left, leaves) + findLeaves(root->right, leaves);
  }
};

int main() {
  Solution solution;
  TreeNode* root1 = new TreeNode(3);
  root1->left = new TreeNode(5);
  root1->right = new TreeNode(1);
  root1->left->left = new TreeNode(6);
  root1->left->right = new TreeNode(2);
  root1->left->right->left = new TreeNode(7);
  root1->left->right->right = new TreeNode(4);
  root1->right->left = new TreeNode(9);
  root1->right->right = new TreeNode(8);
  TreeNode* root2 = new TreeNode(3);
  root2->left = new TreeNode(5);
  root2->right = new TreeNode(1);
  root2->left->left = new TreeNode(6);
  root2->left->right = new TreeNode(7);
  root2->right->left = new TreeNode(4);
  root2->right->right = new TreeNode(2);
  root2->right->right->left = new TreeNode(9);
  root2->right->right->right = new TreeNode(8);
  cout << solution.leafSimilar(root1, root2) << endl;
  return 0;
}