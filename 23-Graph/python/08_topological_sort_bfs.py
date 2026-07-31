from collections import deque
from typing import List

class Solution:
    def topoSort(self, V: int, adj: List[List[int]]) -> List[int]:
        indegree = [0] * V
        for i in range(V):
            for neighbor in adj[i]:
                indegree[neighbor] += 1

        queue = deque([i for i in range(V) if indegree[i] == 0])
        result = []

        while queue:
            node = queue.popleft()
            result.append(node)
            for neighbor in adj[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        return result
