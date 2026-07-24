class Solution {
public:
    bool graphColoring(vector<vector<int>>& edges, int m, int n) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, 0);
        return solve(0, n, m, adj, color);
    }

private:
    bool solve(int node, int n, int m, const vector<vector<int>>& adj, vector<int>& color) {
        if (node == n) return true;

        for (int c = 1; c <= m; c++) {
            if (isSafe(node, c, adj, color)) {
                color[node] = c;
                if (solve(node + 1, n, m, adj, color)) return true;
                color[node] = 0;
            }
        }
        return false;
    }

    bool isSafe(int node, int c, const vector<vector<int>>& adj, const vector<int>& color) {
        for (int neighbor : adj[node]) {
            if (color[neighbor] == c) return false;
        }
        return true;
    }
};
