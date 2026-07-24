class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9

        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                digit = int(board[i][j]) - 1
                bit = 1 << digit
                rows[i] |= bit
                cols[j] |= bit
                boxes[(i // 3) * 3 + (j // 3)] |= bit

        def dfs():
            row, col = -1, -1
            min_choices = 10

            for i in range(9):
                for j in range(9):
                    if board[i][j] != '.':
                        continue
                    box = (i // 3) * 3 + (j // 3)
                    available = ~(rows[i] | cols[j] | boxes[box]) & 511
                    choices = available.bit_count()
                    if choices < min_choices:
                        min_choices = choices
                        row, col = i, j

            if row == -1:
                return True

            box = (row // 3) * 3 + (col // 3)
            available = ~(rows[row] | cols[col] | boxes[box]) & 511

            while available:
                bit = available & -available
                digit = (bit - 1).bit_length()

                board[row][col] = str(digit + 1)
                rows[row] |= bit
                cols[col] |= bit
                boxes[box] |= bit

                if dfs():
                    return True

                rows[row] ^= bit
                cols[col] ^= bit
                boxes[box] ^= bit
                board[row][col] = '.'

                available &= available - 1

            return False

        dfs()
