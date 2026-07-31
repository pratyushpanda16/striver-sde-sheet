from typing import List

class Solution:
    def isCyclic(self, N: int, adj: List[List[int]]) -> bool:
        visited = [0] * N

        def dfs_check(node: int) -> bool:
            visited[node] = 1
            for neighbor in adj[node]:
                if visited[neighbor] == 1:
                    return True
                elif visited[neighbor] == 0:
                    if dfs_check(neighbor):
                        return True
            visited[node] = 2
            return False

        for i in range(N):
            if visited[i] == 0:
                if dfs_check(i):
                    return True
        return False
