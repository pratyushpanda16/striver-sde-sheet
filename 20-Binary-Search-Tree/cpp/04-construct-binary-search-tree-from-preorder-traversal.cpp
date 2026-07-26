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
    vector<int> preorder;

    TreeNode* dfs(int i, int j) {
        if (i > j) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[i]);
        int l = i + 1, r = j + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (preorder[mid] > preorder[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        root->left = dfs(i + 1, l - 1);
        root->right = dfs(l, j);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->preorder = preorder;
        return dfs(0, preorder.size() - 1);
    }
};
