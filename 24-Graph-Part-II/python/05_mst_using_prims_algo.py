import heapq
from typing import List

class Solution:
    def spanningTree(self, V: int, adj: List[List[List[int]]]) -> int:
        visited = [False] * V
        # (weight, node)
        pq = [(0, 0)]

        total_sum = 0
        while pq:
            weight, node = heapq.heappop(pq)

            if visited[node]:
                continue
            visited[node] = True
            total_sum += weight

            for neighbor in adj[node]:
                adj_node, adj_weight = neighbor[0], neighbor[1]
                if not visited[adj_node]:
                    heapq.heappush(pq, (adj_weight, adj_node))

        return total_sum
