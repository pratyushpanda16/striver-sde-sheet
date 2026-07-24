class Solution:
    def graphColoring(self, edges: List[List[int]], m: int, n: int) -> bool:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        color = [0] * n

        def is_safe(node, c):
            for neighbor in adj[node]:
                if color[neighbor] == c:
                    return False
            return True

        def solve(node):
            if node == n:
                return True

            for c in range(1, m + 1):
                if is_safe(node, c):
                    color[node] = c
                    if solve(node + 1):
                        return True
                    color[node] = 0
            return False

        return solve(0)
