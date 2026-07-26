#include <climits>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    long long prev = LLONG_MIN;

    bool inorder(TreeNode* node) {
        if (!node) return true;

        if (!inorder(node->left)) return false;

        if (node->val <= prev) return false;
        prev = node->val;

        return inorder(node->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};
