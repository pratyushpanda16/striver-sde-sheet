import heapq
from typing import List

class Solution:
    def dijkstra(self, V: int, edges: List[List[int]], S: int) -> List[int]:
        adj = [[] for _ in range(V)]
        for u, v, weight in edges:
            adj[u].append((v, weight))
            adj[v].append((u, weight))

        dist = [float('inf')] * V
        dist[S] = 0

        # (distance, node)
        pq = [(0, S)]

        while pq:
            d, node = heapq.heappop(pq)

            if d > dist[node]:
                continue

            for nxt, weight in adj[node]:
                if dist[node] + weight < dist[nxt]:
                    dist[nxt] = dist[node] + weight
                    heapq.heappush(pq, (dist[nxt], nxt))

        return dist
