class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                result.push_back(current->val);
                current = current->right;
            } else {
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    result.push_back(current->val);
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
                    current = current->right;
                }
            }
        }

        return result;
    }
};
