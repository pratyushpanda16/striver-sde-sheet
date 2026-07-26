class Solution {
    vector<vector<int>> nodes;

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            if (a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
        });

        vector<vector<int>> ans;
        int prev = -2000;
        for (const auto& node : nodes) {
            int j = node[0], val = node[2];
            if (prev != j) {
                ans.push_back({});
                prev = j;
            }
            ans.back().push_back(val);
        }

        return ans;
    }

private:
    void dfs(TreeNode* root, int i, int j) {
        if (root == nullptr) return;
        nodes.push_back({j, i, root->val});
        dfs(root->left, i + 1, j - 1);
        dfs(root->right, i + 1, j + 1);
    }
};
