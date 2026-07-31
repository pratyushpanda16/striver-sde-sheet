from collections import deque
from typing import List

class Solution:
    def isBipartite(self, V: int, edges: List[List[int]]) -> bool:
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        color = [-1] * V

        def bfs_check(src: int) -> bool:
            queue = deque([src])
            color[src] = 0

            while queue:
                node = queue.popleft()
                for neighbor in adj[node]:
                    if color[neighbor] == -1:
                        color[neighbor] = 1 - color[node]
                        queue.append(neighbor)
                    elif color[neighbor] == color[node]:
                        return False
            return True

        for i in range(V):
            if color[i] == -1:
                if not bfs_check(i):
                    return False
        return True
