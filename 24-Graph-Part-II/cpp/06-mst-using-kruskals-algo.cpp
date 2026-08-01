#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int find(int node, vector<int>& parent) {
        if (parent[node] != node) {
            parent[node] = find(parent[node], parent);
        }
        return parent[node];
    }

    void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    int spanningTree(int V, vector<vector<vector<int>>>& adj) {
        vector<vector<int>> edges;
        for (int u = 0; u < V; u++) {
            for (auto& neighbor : adj[u]) {
                int v = neighbor[0];
                int weight = neighbor[1];
                if (u < v) {
                    edges.push_back({weight, u, v});
                }
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int sum = 0;
        for (auto& edge : edges) {
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];
            int pu = find(u, parent);
            int pv = find(v, parent);
            if (pu != pv) {
                sum += weight;
                unite(pu, pv, parent, rank);
            }
        }

        return sum;
    }
};
