import java.util.*;

class Solution {
    private int[] parent;
    private int[] rank;
    private int count;

    public int numIslands(char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        parent = new int[rows * cols];
        rank = new int[rows * cols];
        count = 0;

        // Initialize: each '1' cell is its own parent
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    int id = i * cols + j;
                    parent[id] = id;
                    count++;
                }
            }
        }

        // Union adjacent '1' cells (only right and down to avoid double-processing)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    int id = i * cols + j;
                    if (j + 1 < cols && grid[i][j + 1] == '1') {
                        union(id, i * cols + j + 1);
                    }
                    if (i + 1 < rows && grid[i + 1][j] == '1') {
                        union(id, (i + 1) * cols + j);
                    }
                }
            }
        }

        return count;
    }

    private int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    private void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return; // Already in the same set

        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        count--; // Merging two sets reduces island count
    }
}
