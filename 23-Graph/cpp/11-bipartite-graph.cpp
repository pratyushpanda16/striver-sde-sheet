#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);

        for (int u = 0; u < n; u++) {
            if (graph[u].empty()) continue;

            for (size_t i = 1; i < graph[u].size(); i++) {
                unite(graph[u][0], graph[u][i]);
            }
            if (find(u) == find(graph[u][0])) return false;
        }
        return true;
    }
};
