from collections import deque
from typing import List

class Solution:
    def dfsOfGraph(self, V: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        result = []
        visited = [False] * V
        stack = [0]
        visited[0] = True

        while stack:
            node = stack.pop()
            result.append(node)
            for i in range(len(adj[node]) - 1, -1, -1):
                nxt = adj[node][i]
                if not visited[nxt]:
                    visited[nxt] = True
                    stack.append(nxt)

        return result

    def bfsOfGraph(self, V: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        result = []
        visited = [False] * V
        queue = deque([0])
        visited[0] = True

        while queue:
            node = queue.popleft()
            result.append(node)
            for nxt in adj[node]:
                if not visited[nxt]:
                    visited[nxt] = True
                    queue.append(nxt)

        return result
