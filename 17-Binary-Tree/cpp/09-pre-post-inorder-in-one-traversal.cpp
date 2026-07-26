class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<int> inorder, preorder, postorder;
        traverse(root, inorder, preorder, postorder);

        return {inorder, preorder, postorder};
    }

private:
    void traverse(TreeNode* node, vector<int>& inorder, vector<int>& preorder, vector<int>& postorder) {
        if (node == nullptr) return;

        preorder.push_back(node->data);
        traverse(node->left, inorder, preorder, postorder);
        inorder.push_back(node->data);
        traverse(node->right, inorder, preorder, postorder);
        postorder.push_back(node->data);
    }
};
