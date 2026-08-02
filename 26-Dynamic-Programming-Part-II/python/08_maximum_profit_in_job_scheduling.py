from typing import List

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n = len(startTime)
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])

        dp = [0] * (n + 1)

        for i in range(1, n + 1):
            curr_start, _, curr_profit = jobs[i - 1]

            lo, hi, idx = 0, i - 1, 0
            while lo < hi:
                mid = (lo + hi + 1) // 2
                if jobs[mid - 1][1] <= curr_start:
                    idx = mid
                    lo = mid
                else:
                    hi = mid - 1

            dp[i] = max(dp[i - 1], dp[idx] + curr_profit)

        return dp[n]
