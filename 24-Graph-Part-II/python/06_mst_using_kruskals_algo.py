from typing import List

class Solution:
    def spanningTree(self, V: int, adj: List[List[List[int]]]) -> int:
        edges = []
        for u in range(V):
            for neighbor in adj[u]:
                v, weight = neighbor[0], neighbor[1]
                if u < v:
                    edges.append((weight, u, v))

        edges.sort()

        parent = list(range(V))
        rank = [0] * V

        def find(node):
            if parent[node] != node:
                parent[node] = find(parent[node])
            return parent[node]

        def union(u, v):
            if rank[u] < rank[v]:
                parent[u] = v
            elif rank[u] > rank[v]:
                parent[v] = u
            else:
                parent[v] = u
                rank[u] += 1

        total_sum = 0
        for weight, u, v in edges:
            pu, pv = find(u), find(v)
            if pu != pv:
                total_sum += weight
                union(pu, pv)

        return total_sum
