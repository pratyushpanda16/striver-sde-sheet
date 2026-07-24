class Solution {
    public int findMedian(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int low = 1, high = (int) 1e9;
        int required = (n * m) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int count = countSmallerOrEqual(matrix, mid);

            if (count <= required) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }

    private int countSmallerOrEqual(int[][] matrix, int x) {
        int count = 0;
        for (int[] row : matrix) {
            count += countInRow(row, x);
        }
        return count;
    }

    private int countInRow(int[] row, int x) {
        int low = 0, high = row.length - 1;
        int ans = row.length;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] <= x) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
}
