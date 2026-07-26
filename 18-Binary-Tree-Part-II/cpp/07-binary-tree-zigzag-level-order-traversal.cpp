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
    void dfs(TreeNode* node, int level, vector<vector<int>>& result) {
        if (!node) return;

        if (level == result.size()) {
            result.push_back(vector<int>());
        }

        if (level % 2 == 0) {
            result[level].push_back(node->val);
        } else {
            result[level].insert(result[level].begin(), node->val);
        }

        dfs(node->left, level + 1, result);
        dfs(node->right, level + 1, result);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
};
