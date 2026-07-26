#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
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
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        stack<TreeNode*> st;
        vector<TreeNode*> order;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            order.push_back(node);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        unordered_map<TreeNode*, int> gain;
        int maxSum = INT_MIN;
        for (int i = (int)order.size() - 1; i >= 0; --i) {
            TreeNode* node = order[i];
            int leftGain = max(gain.count(node->left) ? gain[node->left] : 0, 0);
            int rightGain = max(gain.count(node->right) ? gain[node->right] : 0, 0);
            maxSum = max(maxSum, node->val + leftGain + rightGain);
            gain[node] = node->val + max(leftGain, rightGain);
        }
        return maxSum;
    }
};
