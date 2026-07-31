from collections import deque
from typing import List

class Solution:
    def isCycle(self, V: int, adj: List[List[int]]) -> bool:
        visited = [False] * V

        def bfs_check(src: int) -> bool:
            queue = deque([(src, -1)])
            visited[src] = True

            while queue:
                node, parent = queue.popleft()
                for neighbor in adj[node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        queue.append((neighbor, node))
                    elif neighbor != parent:
                        return True
            return False

        for i in range(V):
            if not visited[i]:
                if bfs_check(i):
                    return True
        return False
