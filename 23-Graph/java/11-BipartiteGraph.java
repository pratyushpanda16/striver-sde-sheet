import java.util.*;

class Solution {
    private int[] parent;
    private int[] rank;

    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int u = 0; u < n; u++) {
            if (graph[u].length == 0) continue;

            // Union all neighbors of u together
            for (int i = 1; i < graph[u].length; i++) {
                union(graph[u][0], graph[u][i]);
            }
            // u and its neighbor must be in different sets
            if (find(u) == find(graph[u][0])) return false;
        }
        return true;
    }

    private int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    private void union(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) { int tmp = px; px = py; py = tmp; }
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
}
