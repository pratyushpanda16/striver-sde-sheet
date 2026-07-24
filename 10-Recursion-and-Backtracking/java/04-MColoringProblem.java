class Solution {
    boolean graphColoring(int[][] edges, int m, int n) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        int[] color = new int[n];
        return solve(0, n, m, adj, color);
    }

    private boolean solve(int node, int n, int m, List<List<Integer>> adj, int[] color) {
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

    private boolean isSafe(int node, int c, List<List<Integer>> adj, int[] color) {
        for (int neighbor : adj.get(node)) {
            if (color[neighbor] == c) return false;
        }
        return true;
    }
}
