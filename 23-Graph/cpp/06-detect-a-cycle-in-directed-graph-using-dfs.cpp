#include <vector>

using namespace std;

class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 1) {
                return true;
            } else if (visited[neighbor] == 0) {
                if (dfsCheck(neighbor, adj, visited)) {
                    return true;
                }
            }
        }
        visited[node] = 2;
        return false;
    }

public:
    bool isCyclic(int N, vector<vector<int>>& adj) {
        vector<int> visited(N, 0);
        for (int i = 0; i < N; i++) {
            if (visited[i] == 0) {
                if (dfsCheck(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
