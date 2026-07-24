class Solution:
    def isSubsetSum(self, arr: List[int], target: int) -> bool:
        n = len(arr)
        dp = [[False] * (target + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = True

        for i in range(1, n + 1):
            for s in range(1, target + 1):
                not_take = dp[i - 1][s]
                take = False
                if arr[i - 1] <= s:
                    take = dp[i - 1][s - arr[i - 1]]
                dp[i][s] = take or not_take

        return dp[n][target]
