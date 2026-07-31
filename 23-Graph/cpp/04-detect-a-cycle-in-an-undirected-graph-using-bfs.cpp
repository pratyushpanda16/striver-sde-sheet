#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool bfsCheck(int src, int V, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int, int>> q;
        visited[src] = true;
        q.push({src, -1});

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsCheck(i, V, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
