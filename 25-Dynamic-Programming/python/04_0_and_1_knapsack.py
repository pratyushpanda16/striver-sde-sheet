from typing import List

class Solution:
    def knapsack01(self, wt: List[int], val: List[int], n: int, W: int) -> int:
        dp = [0] * (W + 1)

        for i in range(n):
            for w in range(W, wt[i] - 1, -1):
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]])

        return dp[W]
