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
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string pathToStart, pathToDest;
    dfs(root, startValue, pathToStart);
    dfs(root, destValue, pathToDest);

    // 找 LCA
    int i = 0;
    while (i < pathToStart.size() && i < pathToDest.size() &&
           pathToStart[i] == pathToDest[i]) {
      ++i;
    }

    string result(pathToStart.size() - i, 'U');  // 向上
    result += pathToDest.substr(i);              // 再往下
    return result;
  }

 private:
  bool dfs(TreeNode* node, int target, string& path) {
    if (!node) return false;
    if (node->val == target) return true;

    path.push_back('L');
    if (dfs(node->left, target, path)) return true;
    path.pop_back();

    path.push_back('R');
    if (dfs(node->right, target, path)) return true;
    path.pop_back();

    return false;
  }
};
