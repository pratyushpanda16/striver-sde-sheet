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
public:
    bool checkChildrenSum(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;
        if (root->val != leftVal + rightVal) return false;
        return checkChildrenSum(root->left) && checkChildrenSum(root->right);
    }
};
