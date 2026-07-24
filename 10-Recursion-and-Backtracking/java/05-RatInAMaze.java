class Solution {
    public List<String> findPath(int[][] grid) {
        List<String> result = new ArrayList<>();
        int n = grid.length;

        if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0) {
            return result;
        }

        boolean[][] visited = new boolean[n][n];
        StringBuilder path = new StringBuilder();

        solve(0, 0, grid, n, visited, path, result);
        return result;
    }

    private static final int[] dx = {1, 0, 0, -1};
    private static final int[] dy = {0, -1, 1, 0};
    private static final char[] dirChar = {'D', 'L', 'R', 'U'};

    private void solve(int x, int y, int[][] grid, int n, boolean[][] visited,
                        StringBuilder path, List<String> result) {
        if (x == n - 1 && y == n - 1) {
            result.add(path.toString());
            return;
        }

        visited[x][y] = true;

        for (int dir = 0; dir < 4; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (isSafe(newX, newY, grid, n, visited)) {
                path.append(dirChar[dir]);
                solve(newX, newY, grid, n, visited, path, result);
                path.deleteCharAt(path.length() - 1);
            }
        }

        visited[x][y] = false;
    }

    private boolean isSafe(int x, int y, int[][] grid, int n, boolean[][] visited) {
        return x >= 0 && x < n && y >= 0 && y < n
                && grid[x][y] == 1
                && !visited[x][y];
    }
}
