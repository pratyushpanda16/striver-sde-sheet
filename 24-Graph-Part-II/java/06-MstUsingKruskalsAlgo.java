import java.util.*;

class Solution {
    public int spanningTree(int V, List<List<List<Integer>>> adj) {
        List<int[]> edges = new ArrayList<>();
        for (int u = 0; u < V; u++) {
            for (List<Integer> neighbor : adj.get(u)) {
                int v = neighbor.get(0);
                int weight = neighbor.get(1);
                if (u < v) {
                    edges.add(new int[]{weight, u, v});
                }
            }
        }

        edges.sort((a, b) -> a[0] - b[0]);

        int[] parent = new int[V];
        int[] rank = new int[V];
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int sum = 0;
        for (int[] edge : edges) {
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];
            int pu = find(u, parent);
            int pv = find(v, parent);
            if (pu != pv) {
                sum += weight;
                union(pu, pv, parent, rank);
            }
        }

        return sum;
    }

    private int find(int node, int[] parent) {
        if (parent[node] != node) {
            parent[node] = find(parent[node], parent);
        }
        return parent[node];
    }

    private void union(int u, int v, int[] parent, int[] rank) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}
