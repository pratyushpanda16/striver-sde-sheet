#include <vector>
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
    int postIndex;
    int inIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int stop) {
        if (postIndex < 0 || inorder[inIndex] == stop) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postIndex--]);
        root->right = build(inorder, postorder, root->val);
        inIndex--;
        root->left = build(inorder, postorder, stop);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = (int)postorder.size() - 1;
        inIndex = (int)inorder.size() - 1;
        return build(inorder, postorder, INT_MAX);
    }
};
