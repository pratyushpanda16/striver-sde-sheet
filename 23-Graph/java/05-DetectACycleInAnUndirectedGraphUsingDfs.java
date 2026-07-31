import java.util.*;

class Solution {
    public boolean isCycle(int V, List<Integer>[] adj) {
        boolean[] visited = new boolean[V];
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCheck(i, -1, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfsCheck(int node, int parent, List<Integer>[] adj, boolean[] visited) {
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
}
