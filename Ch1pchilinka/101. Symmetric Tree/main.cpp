#include <istream>
#include <vector>
#include <stack>

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
  bool isSymmetric(TreeNode *root) {
    std::stack<TreeNode *> s1, s2;
    TreeNode *node1 = root->left;
    TreeNode *node2 = root->right;
    while (!s1.empty() || node1 != nullptr)
      if (node1 != nullptr) {
        if (node2 == nullptr) {
          return false;
        }
        s1.push(node1);
        s2.push(node2);
        if (node1->val != node2->val) {
          return false;
        }
        node1 = node1->left;
        node2 = node2->right;
      } else if (node2 != nullptr) {
        return false;
      } else {
        node1 = s1.top();
        node2 = s2.top();
        s1.pop();
        s2.pop();
        node1 = node1->right;
        node2 = node2->left;
      }
    if (node2 != nullptr) {
      return false;
    }
    return true;
  }
};