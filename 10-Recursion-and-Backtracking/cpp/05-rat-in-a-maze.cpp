class Solution {
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    char dirChar[4] = {'D', 'L', 'R', 'U'};

public:
    vector<string> findPath(vector<vector<int>>& grid) {
        vector<string> result;
        int n = grid.size();

        if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0) return result;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path = "";
        solve(0, 0, grid, n, visited, path, result);
        return result;
    }

private:
    void solve(int x, int y, const vector<vector<int>>& grid, int n,
               vector<vector<bool>>& visited, string& path, vector<string>& result) {
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }

        visited[x][y] = true;

        for (int dir = 0; dir < 4; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (isSafe(newX, newY, grid, n, visited)) {
                path.push_back(dirChar[dir]);
                solve(newX, newY, grid, n, visited, path, result);
                path.pop_back();
            }
        }

        visited[x][y] = false;
    }

    bool isSafe(int x, int y, const vector<vector<int>>& grid, int n, const vector<vector<bool>>& visited) {
        return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 && !visited[x][y];
    }
};
