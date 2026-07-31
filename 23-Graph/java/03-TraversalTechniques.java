import java.util.*;

class Solution {
    public List<Integer> dfsOfGraph(int V, List<List<Integer>> edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (List<Integer> e : edges) {
            int u = e.get(0), v = e.get(1);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[V];
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(0);
        visited[0] = true;

        while (!stack.isEmpty()) {
            int node = stack.pop();
            result.add(node);
            List<Integer> neighbors = adj.get(node);
            for (int i = neighbors.size() - 1; i >= 0; i--) {
                int next = neighbors.get(i);
                if (!visited[next]) {
                    visited[next] = true;
                    stack.push(next);
                }
            }
        }

        return result;
    }

    public List<Integer> bfsOfGraph(int V, List<List<Integer>> edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (List<Integer> e : edges) {
            int u = e.get(0), v = e.get(1);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[V];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        visited[0] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            result.add(node);
            for (int next : adj.get(node)) {
                if (!visited[next]) {
                    visited[next] = true;
                    queue.add(next);
                }
            }
        }

        return result;
    }
}
