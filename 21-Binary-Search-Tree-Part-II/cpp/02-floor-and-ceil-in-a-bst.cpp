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
    int findFloor(TreeNode* root, int key) {
        int floor = -1;
        while (root) {
            if (root->val == key) {
                return root->val;
            } else if (root->val < key) {
                floor = root->val;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
    }

    int findCeil(TreeNode* root, int key) {
        int ceil = -1;
        while (root) {
            if (root->val == key) {
                return root->val;
            } else if (root->val > key) {
                ceil = root->val;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ceil;
    }

public:
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        int floor = findFloor(root, key);
        int ceil = findCeil(root, key);
        return {floor, ceil};
    }
};
