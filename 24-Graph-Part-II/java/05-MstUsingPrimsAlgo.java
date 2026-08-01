import java.util.*;

class Solution {
    public int spanningTree(int V, List<List<List<Integer>>> adj) {
        boolean[] visited = new boolean[V];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0, 0});

        int sum = 0;
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int weight = curr[0];
            int node = curr[1];

            if (visited[node]) continue;
            visited[node] = true;
            sum += weight;

            for (List<Integer> neighbor : adj.get(node)) {
                int adjNode = neighbor.get(0);
                int adjWeight = neighbor.get(1);
                if (!visited[adjNode]) {
                    pq.add(new int[]{adjWeight, adjNode});
                }
            }
        }

        return sum;
    }
}
