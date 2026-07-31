import java.util.*;

class Solution {
    public boolean isCycle(int V, List<Integer>[] adj) {
        boolean[] visited = new boolean[V];
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsCheck(i, V, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean bfsCheck(int src, int V, List<Integer>[] adj, boolean[] visited) {
        Queue<int[]> queue = new LinkedList<>();
        visited[src] = true;
        queue.add(new int[]{src, -1});

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int node = curr[0];
            int parent = curr[1];

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(new int[]{neighbor, node});
                } else if (neighbor != parent) {
                    return true;
                }
            }
        }
        return false;
    }
}
