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
    vector<char> startPath, destPath;
    dfs(root, startValue, destValue, {}, startPath, destPath);

    // 找出共同 prefix 長度
    int i = 0, common = min(startPath.size(), destPath.size());
    while (i < common && startPath[i] == destPath[i]) {
      ++i;
    }

    // 從 start node 到 LCA 要回傳 "U"
    string result(startPath.size() - i, 'U');

    // 從 LCA 到 dest node
    for (int j = i; j < destPath.size(); ++j) {
      result += destPath[j];
    }

    return result;
  }

 private:
  // currentPath 是遞迴時帶入的路徑
  bool dfs(TreeNode* node, int startValue, int destValue,
           vector<char> currentPath, vector<char>& startPath,
           vector<char>& destPath) {
    if (!node) return false;

    if (node->val == startValue) {
      startPath = currentPath;
    }
    if (node->val == destValue) {
      destPath = currentPath;
    }

    // 若兩個路徑都找到就停止搜尋
    if (!startPath.empty() && !destPath.empty()) {
      return true;
    }

    currentPath.push_back('L');
    if (dfs(node->left, startValue, destValue, currentPath, startPath,
            destPath)) {
      return true;
    }
    currentPath.back() = 'R';
    if (dfs(node->right, startValue, destValue, currentPath, startPath,
            destPath)) {
      return true;
    }

    return false;
  }
};
