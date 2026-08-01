from typing import List

class Solution:
    def matrixMultiplication(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0] * n for _ in range(n)]

        for length in range(2, n):
            for i in range(1, n - length + 1):
                j = i + length - 1
                dp[i][j] = float('inf')
                for k in range(i, j):
                    cost = dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j]
                    dp[i][j] = min(dp[i][j], cost)

        return dp[1][n - 1]
