class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        queens = [0] * n

        def backtrack(row, cols, diags, anti_diags):
            if row == n:
                board = []
                for r in range(n):
                    row_str = ['.'] * n
                    row_str[queens[r]] = 'Q'
                    board.append("".join(row_str))
                result.append(board)
                return

            available = ((1 << n) - 1) & ~(cols | diags | anti_diags)
            while available:
                position = available & (-available)
                col = (position - 1).bit_length()
                queens[row] = col

                backtrack(
                    row + 1,
                    cols | position,
                    (diags | position) << 1,
                    (anti_diags | position) >> 1
                )

                available &= available - 1

        backtrack(0, 0, 0, 0)
        return result
