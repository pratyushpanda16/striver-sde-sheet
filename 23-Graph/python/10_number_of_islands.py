from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        parent = {}
        rank = {}
        self.count = 0

        def find(i):
            if parent[i] != i:
                parent[i] = find(parent[i])
            return parent[i]

        def union(i, j):
            root_i = find(i)
            root_j = find(j)
            if root_i != root_j:
                if rank[root_i] < rank[root_j]:
                    parent[root_i] = root_j
                elif rank[root_i] > rank[root_j]:
                    parent[root_j] = root_i
                else:
                    parent[root_j] = root_i
                    rank[root_i] += 1
                self.count -= 1

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1':
                    cell_id = r * cols + c
                    parent[cell_id] = cell_id
                    rank[cell_id] = 0
                    self.count += 1

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1':
                    cell_id = r * cols + c
                    if c + 1 < cols and grid[r][c + 1] == '1':
                        union(cell_id, r * cols + c + 1)
                    if r + 1 < rows and grid[r + 1][c] == '1':
                        union(cell_id, (r + 1) * cols + c)

        return self.count
