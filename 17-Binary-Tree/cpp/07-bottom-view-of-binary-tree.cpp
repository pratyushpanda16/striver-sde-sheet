class Solution {
public:
    vector<int> bottomView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;
            int hd = current.second;

            mp[hd] = node->data;

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto const& [hd, val] : mp) {
            result.push_back(val);
        }

        return result;
    }
};
