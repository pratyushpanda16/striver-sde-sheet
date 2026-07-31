import java.util.*;

class Solution {
    public boolean isCyclic(int N, List<List<Integer>> adj) {
        int[] visited = new int[N];
        for (int i = 0; i < N; i++) {
            if (visited[i] == 0) {
                if (dfsCheck(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfsCheck(int node, List<List<Integer>> adj, int[] visited) {
        visited[node] = 1;
        for (int neighbor : adj.get(node)) {
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
}
