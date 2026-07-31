#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool bfsCheck(int src, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        q.push(src);
        color[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfsCheck(i, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
