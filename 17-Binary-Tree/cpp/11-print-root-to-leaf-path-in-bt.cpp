class Solution {
public:
    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, path, result);
        return result;
    }

private:
    void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& result) {
        if (node == nullptr) return;

        path.push_back(node->data);

        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);
        } else {
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }

        path.pop_back();
    }
};
