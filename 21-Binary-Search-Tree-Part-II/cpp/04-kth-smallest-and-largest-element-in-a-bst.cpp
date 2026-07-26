#include <vector>

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
    void inorderTraversal(TreeNode* node, vector<int>& list) {
        if (!node) return;
        inorderTraversal(node->left, list);
        list.push_back(node->val);
        inorderTraversal(node->right, list);
    }

public:
    vector<int> kLargesSmall(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        int kSmallest = inorder[k - 1];
        int kLargest = inorder[inorder.size() - k];

        return {kSmallest, kLargest};
    }
};
