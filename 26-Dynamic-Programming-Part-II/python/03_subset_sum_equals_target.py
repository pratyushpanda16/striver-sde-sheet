from typing import List

class Solution:
    def isSubsetSum(self, arr: List[int], target: int) -> bool:
        n = len(arr)
        dp = [[False] * (target + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = True

        for i in range(1, n + 1):
            for sum_val in range(1, target + 1):
                not_take = dp[i - 1][sum_val]
                take = False
                if arr[i - 1] <= sum_val:
                    take = dp[i - 1][sum_val - arr[i - 1]]

                dp[i][sum_val] = take or not_take

        return dp[n][target]
