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
  void InOrder(std::vector<std::vector<int>> &vec, TreeNode *root, int level) {
    if (root == nullptr) {
      return;
    }
    if (vec.size() <= level) {
      vec.push_back(std::vector<int>{root->val});
    } else {
      vec[level].push_back(root->val);
    }
    InOrder(vec, root->left, level + 1);
    InOrder(vec, root->right, level + 1);
  }
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    InOrder(ans, root, 0);
    return ans;
  }
};
