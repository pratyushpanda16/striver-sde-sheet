#include <vector>

using namespace std;

class Solution {
private:
    bool dfsCheck(int node, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCheck(neighbor, node, adj, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCheck(i, -1, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
