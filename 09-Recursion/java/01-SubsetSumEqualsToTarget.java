class Solution {
    public boolean isSubsetSum(int[] arr, int target) {
        int n = arr.length;
        boolean[][] dp = new boolean[n + 1][target + 1];

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int sum = 1; sum <= target; sum++) {
                boolean notTake = dp[i - 1][sum];
                boolean take = false;

                if (arr[i - 1] <= sum) {
                    take = dp[i - 1][sum - arr[i - 1]];
                }

                dp[i][sum] = take || notTake;
            }
        }

        return dp[n][target];
    }
}
