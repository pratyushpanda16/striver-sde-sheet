class Solution {
    int maxWidth = 0;
    vector<long long> leftmostIndices;

public:
    int widthOfBinaryTree(TreeNode* root) {
        maxWidth = 0;
        leftmostIndices.clear();
        dfs(root, 0, 0LL);
        return maxWidth;
    }

private:
    void dfs(TreeNode* node, int depth, long long index) {
        if (node == nullptr) return;

        if (depth == (int)leftmostIndices.size()) {
            leftmostIndices.push_back(index);
        }

        long long width = index - leftmostIndices[depth] + 1;
        maxWidth = max(maxWidth, (int)width);

        long long normalizedIndex = index - leftmostIndices[depth];
        dfs(node->left, depth + 1, 2 * normalizedIndex);
        dfs(node->right, depth + 1, 2 * normalizedIndex + 1);
    }
};
