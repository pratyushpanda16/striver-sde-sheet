class Solution {
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int digit = board[i][j] - '1';
                int bit = 1 << digit;

                rows[i] |= bit;
                cols[j] |= bit;
                boxes[(i / 3) * 3 + (j / 3)] |= bit;
            }
        }

        dfs(board);
    }

private:
    bool dfs(vector<vector<char>>& board) {
        int row = -1, col = -1;
        int minChoices = 10;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;

                int box = (i / 3) * 3 + (j / 3);
                int available = ~(rows[i] | cols[j] | boxes[box]) & 511;
                int choices = __builtin_popcount(available);

                if (choices < minChoices) {
                    minChoices = choices;
                    row = i;
                    col = j;
                }
            }
        }

        if (row == -1) return true;

        int box = (row / 3) * 3 + (col / 3);
        int available = ~(rows[row] | cols[col] | boxes[box]) & 511;

        while (available != 0) {
            int bit = available & -available;
            int digit = __builtin_ctz(bit);

            board[row][col] = (char)(digit + '1');

            rows[row] |= bit;
            cols[col] |= bit;
            boxes[box] |= bit;

            if (dfs(board)) return true;

            rows[row] ^= bit;
            cols[col] ^= bit;
            boxes[box] ^= bit;

            board[row][col] = '.';

            available &= (available - 1);
        }

        return false;
    }
};
