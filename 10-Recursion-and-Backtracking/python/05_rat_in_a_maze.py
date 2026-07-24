class Solution:
    def findPath(self, grid: List[List[int]]) -> List[str]:
        n = len(grid)
        result = []

        if grid[0][0] == 0 or grid[n - 1][n - 1] == 0:
            return result

        visited = [[False] * n for _ in range(n)]
        dx = [1, 0, 0, -1]
        dy = [0, -1, 1, 0]
        dir_char = ['D', 'L', 'R', 'U']

        def solve(x, y, path):
            if x == n - 1 and y == n - 1:
                result.append("".join(path))
                return

            visited[x][y] = True

            for d in range(4):
                nx, ny = x + dx[d], y + dy[d]
                if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1 and not visited[nx][ny]:
                    path.append(dir_char[d])
                    solve(nx, ny, path)
                    path.pop()

            visited[x][y] = False

        solve(0, 0, [])
        return result
