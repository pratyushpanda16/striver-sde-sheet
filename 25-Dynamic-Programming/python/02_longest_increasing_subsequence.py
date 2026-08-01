from typing import List

class Solution:
    def LIS(self, nums: List[int]) -> int:
        tails = [0] * len(nums)
        size = 0

        for num in nums:
            lo, hi = 0, size
            while lo < hi:
                mid = (lo + hi) // 2
                if tails[mid] < num:
                    lo = mid + 1
                else:
                    hi = mid
            tails[lo] = num
            if lo == size:
                size += 1

        return size
