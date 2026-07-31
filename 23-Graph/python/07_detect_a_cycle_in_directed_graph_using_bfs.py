from collections import deque
from typing import List

class Solution:
    def isCyclic(self, N: int, adj: List[List[int]]) -> bool:
        indegree = [0] * N
        for i in range(N):
            for neighbor in adj[i]:
                indegree[neighbor] += 1

        queue = deque([i for i in range(N) if indegree[i] == 0])
        count = 0

        while queue:
            node = queue.popleft()
            count += 1
            for neighbor in adj[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        return count != N
