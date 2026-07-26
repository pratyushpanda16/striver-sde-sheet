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
    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        if (prev == nullptr) {
            head = node;
        } else {
            prev->right = node;
            node->left = prev;
        }
        prev = node;

        inorder(node->right);
    }

public:
    TreeNode* bToDLL(TreeNode* root) {
        inorder(root);
        return head;
    }
};
