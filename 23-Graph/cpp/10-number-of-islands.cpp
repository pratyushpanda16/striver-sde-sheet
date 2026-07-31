#include <vector>

using namespace std;

class Solution {
private:
    vector<int> parent;
    vector<int> rank;
    int count;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        count--;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        parent.resize(rows * cols);
        rank.resize(rows * cols, 0);
        count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    int id = i * cols + j;
                    parent[id] = id;
                    count++;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    int id = i * cols + j;
                    if (j + 1 < cols && grid[i][j + 1] == '1') {
                        unite(id, i * cols + j + 1);
                    }
                    if (i + 1 < rows && grid[i + 1][j] == '1') {
                        unite(id, (i + 1) * cols + j);
                    }
                }
            }
        }

        return count;
    }
};
