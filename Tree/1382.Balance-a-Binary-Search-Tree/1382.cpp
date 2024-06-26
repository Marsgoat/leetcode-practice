#include <iostream>
#include <vector>

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
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    inorder(root, nums);
    return build(nums, 0, nums.size() - 1);
  }

 private:
  void inorder(TreeNode* root, vector<int>& nums) {
    if (root == nullptr) return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }

  TreeNode* build(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);
    return root;
  }
};

int main() {
  Solution solution;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  cout << solution.balanceBST(root) << endl;
  return 0;
}