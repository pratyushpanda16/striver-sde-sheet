from typing import List

class Solution:
    def bellman_ford(self, V: int, edges: List[List[int]], S: int) -> List[int]:
        dist = [10**8] * V
        dist[S] = 0

        for _ in range(V - 1):
            for u, v, weight in edges:
                if dist[u] != 10**8 and dist[u] + weight < dist[v]:
                    dist[v] = dist[u] + weight

        for u, v, weight in edges:
            if dist[u] != 10**8 and dist[u] + weight < dist[v]:
                return [-1]

        return dist
