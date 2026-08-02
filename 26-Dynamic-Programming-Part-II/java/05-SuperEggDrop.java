class Solution {
    public int eggDrop(int n, int k) {
        int[] dp = new int[n + 1];
        int moves = 0;
        while (dp[n] < k) {
            moves++;
            for (int eggs = n; eggs >= 1; eggs--) {
                dp[eggs] = dp[eggs] + dp[eggs - 1] + 1;
            }
        }
        return moves;
    }
}
