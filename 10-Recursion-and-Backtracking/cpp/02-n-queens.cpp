class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queens(n);
        backtrack(0, n, 0, 0, 0, queens, result);
        return result;
    }

private:
    void backtrack(int row, int n, int cols, int diags, int antiDiags,
                   vector<int>& queens, vector<vector<string>>& result) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][queens[i]] = 'Q';
            }
            result.push_back(board);
            return;
        }

        int availablePositions = ((1 << n) - 1) & ~(cols | diags | antiDiags);
        while (availablePositions != 0) {
            int position = availablePositions & (-availablePositions);
            int col = __builtin_ctz(position);
            queens[row] = col;

            backtrack(row + 1, n, cols | position,
                     (diags | position) << 1,
                     (antiDiags | position) >> 1,
                     queens, result);

            availablePositions &= availablePositions - 1;
        }
    }
};
