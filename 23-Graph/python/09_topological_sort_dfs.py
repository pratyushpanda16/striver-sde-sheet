from typing import List

class Solution:
    def topoSort(self, V: int, adj: List[List[int]]) -> List[int]:
        visited = [False] * V
        stack = []

        def dfs(node: int):
            visited[node] = True
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    dfs(neighbor)
            stack.append(node)

        for i in range(V):
            if not visited[i]:
                dfs(i)

        return stack[::-1]
