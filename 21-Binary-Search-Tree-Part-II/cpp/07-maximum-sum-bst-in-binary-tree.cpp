#include <vector>
#include <algorithm>

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
    int ans = 0;
    const int inf = 1 << 30;

    // returns {isBST, minVal, maxVal, sum}
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {1, inf, -inf, 0};
        }
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int v = root->val;

        if (l[0] == 1 && r[0] == 1 && l[2] < v && r[1] > v) {
            int s = v + l[3] + r[3];
            ans = max(ans, s);
            return {1, min(l[1], v), max(r[2], v), s};
        }
        return {0, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
