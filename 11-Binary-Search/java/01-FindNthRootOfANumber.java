class Solution {
    public int NthRoot(int N, int M) {
        int low = 1, high = M;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long power = computePower(mid, N, M);

            if (power == M) {
                return mid;
            } else if (power < M) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    private long computePower(int base, int N, int M) {
        long result = 1;
        for (int i = 0; i < N; i++) {
            result *= base;
            if (result > M) {
                return result;
            }
        }
        return result;
    }
}
