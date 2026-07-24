class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        int[] queens = new int[n];

        backtrack(0, n, 0, 0, 0, queens, result);
        return result;
    }

    private void backtrack(int row, int n, int cols, int diags, int antiDiags,
                           int[] queens, List<List<String>> result) {
        if (row == n) {
            result.add(buildBoard(queens, n));
            return;
        }

        int availablePositions = ((1 << n) - 1) & ~(cols | diags | antiDiags);
        while (availablePositions != 0) {
            int position = availablePositions & (-availablePositions);
            int col = Integer.bitCount(position - 1);
            queens[row] = col;

            backtrack(row + 1, n, cols | position,
                     (diags | position) << 1,
                     (antiDiags | position) >> 1,
                     queens, result);

            availablePositions &= availablePositions - 1;
        }
    }

    private List<String> buildBoard(int[] queens, int n) {
        List<String> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            char[] row = new char[n];
            Arrays.fill(row, '.');
            row[queens[i]] = 'Q';
            board.add(new String(row));
        }
        return board;
    }
}
