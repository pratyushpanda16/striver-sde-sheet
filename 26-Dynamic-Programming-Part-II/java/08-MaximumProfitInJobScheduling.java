import java.util.Arrays;

class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        Arrays.sort(jobs, (a, b) -> a[1] - b[1]);

        int[] dp = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            int currStart = jobs[i - 1][0];
            int currProfit = jobs[i - 1][2];

            // binary search for largest index j in [0, i-1) such that jobs[j][1] <= currStart
            int lo = 0, hi = i - 1, idx = 0;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (jobs[mid - 1][1] <= currStart) {
                    idx = mid;
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }

            dp[i] = Math.max(dp[i - 1], dp[idx] + currProfit);
        }

        return dp[n];
    }
}
