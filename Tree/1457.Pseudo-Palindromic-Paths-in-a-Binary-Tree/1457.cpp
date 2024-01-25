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
  int pseudoPalindromicPaths(TreeNode* root) {
    int count = 0;
    dfs(root, 0, count);
    return count;
  }

  void dfs(TreeNode* root, int path, int& count) {
    if (!root) return;

    path ^= (1 << root->val);
    if (!root->left && !root->right) {
      if (path == 0 || (path & (path - 1)) == 0) count++;
    }

    dfs(root->left, path, count);
    dfs(root->right, path, count);
  }
};

int main() {
  Solution solution;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);
  root->right = new TreeNode(1);
  root->right->right = new TreeNode(1);
  cout << solution.pseudoPalindromicPaths(root) << endl;
}