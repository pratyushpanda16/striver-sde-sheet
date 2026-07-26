#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        int rows = image.size(), cols = image[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& dir : directions) {
                int newRow = r + dir.first;
                int newCol = c + dir.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols
                        && image[newRow][newCol] == originalColor) {
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }
        return image;
    }
};
