from typing import List

class Solution:
    def RodCutting(self, price: List[int], n: int) -> int:
        dp = [0] * (n + 1)
        for length in range(1, n + 1):
            for cut in range(1, length + 1):
                dp[length] = max(dp[length], price[cut - 1] + dp[length - cut])
        return dp[n]
