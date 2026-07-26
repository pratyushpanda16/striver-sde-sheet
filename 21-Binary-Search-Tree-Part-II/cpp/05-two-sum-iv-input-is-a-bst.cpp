#include <stack>

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
    void pushAllLeft(TreeNode* node, stack<TreeNode*>& st) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

    void pushAllRight(TreeNode* node, stack<TreeNode*>& st) {
        while (node != nullptr) {
            st.push(node);
            node = node->right;
        }
    }

public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        stack<TreeNode*> leftStack;
        stack<TreeNode*> rightStack;

        pushAllLeft(root, leftStack);
        pushAllRight(root, rightStack);

        TreeNode* leftNode = leftStack.top(); leftStack.pop();
        TreeNode* rightNode = rightStack.top(); rightStack.pop();

        while (leftNode != rightNode) {
            int sum = leftNode->val + rightNode->val;
            if (sum == k) return true;

            if (sum < k) {
                pushAllLeft(leftNode->right, leftStack);
                leftNode = leftStack.top(); leftStack.pop();
            } else {
                pushAllRight(rightNode->left, rightStack);
                rightNode = rightStack.top(); rightStack.pop();
            }
        }

        return false;
    }
};
