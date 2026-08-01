from typing import List

class Solution:
    def maxSumIncreasingSubsequence(self, arr: List[int], n: int) -> int:
        dp = list(arr)
        max_sum = arr[0]

        for i in range(1, n):
            for j in range(i):
                if arr[j] < arr[i] and dp[j] + arr[i] > dp[i]:
                    dp[i] = dp[j] + arr[i]
            max_sum = max(max_sum, dp[i])

        return max_sum
