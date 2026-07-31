from typing import List

class Solution:
    def isCycle(self, V: int, adj: List[List[int]]) -> bool:
        visited = [False] * V

        def dfs_check(node: int, parent: int) -> bool:
            visited[node] = True
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    if dfs_check(neighbor, node):
                        return True
                elif neighbor != parent:
                    return True
            return False

        for i in range(V):
            if not visited[i]:
                if dfs_check(i, -1):
                    return True
        return False
