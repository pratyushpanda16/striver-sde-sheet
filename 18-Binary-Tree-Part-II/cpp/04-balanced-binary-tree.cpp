#include <unordered_map>
#include <stack>
#include <cmath>
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
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        unordered_map<TreeNode*, int> heights;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            bool leftDone = (node->left == nullptr) || heights.count(node->left);
            bool rightDone = (node->right == nullptr) || heights.count(node->right);

            if (!leftDone || !rightDone) {
                st.push(node);
                if (!leftDone) st.push(node->left);
                if (!rightDone) st.push(node->right);
                continue;
            }

            int leftHeight = (node->left == nullptr) ? 0 : heights[node->left];
            int rightHeight = (node->right == nullptr) ? 0 : heights[node->right];

            if (abs(leftHeight - rightHeight) > 1) {
                return false;
            }

            heights[node] = 1 + max(leftHeight, rightHeight);
        }

        return true;
    }
};
