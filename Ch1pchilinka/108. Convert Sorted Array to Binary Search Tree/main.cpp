#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode* NewNode(std::vector<int>& nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int n = (left + right + 1) / 2;
    TreeNode* node = new TreeNode{nums[n], nullptr, nullptr};
    node->left = NewNode(nums, left, n);
    node->right = NewNode(nums, n, right);
    return node;
  }
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
      return NewNode(nums, 0, nums.size() - 1);
  }
};