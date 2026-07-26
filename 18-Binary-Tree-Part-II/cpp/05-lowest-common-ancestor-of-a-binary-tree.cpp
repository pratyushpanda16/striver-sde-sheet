#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> queue;
        parent[root] = nullptr;
        queue.push(root);

        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node->left) {
                parent[node->left] = node;
                queue.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                queue.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestors;
        TreeNode* current = p;
        while (current != nullptr) {
            ancestors.insert(current);
            current = parent[current];
        }

        current = q;
        while (ancestors.find(current) == ancestors.end()) {
            current = parent[current];
        }

        return current;
    }
};
