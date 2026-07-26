class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* previous = nullptr;

        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();

            if (current->right == nullptr || current->right == previous) {
                result.push_back(current->val);
                previous = current;
                st.pop();
                current = nullptr;
            } else {
                current = current->right;
            }
        }

        return result;
    }
};
