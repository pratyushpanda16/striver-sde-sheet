from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        result = nums[0]
        prefix = 0
        suffix = 0
        n = len(nums)

        for i in range(n):
            prefix = (1 if prefix == 0 else prefix) * nums[i]
            suffix = (1 if suffix == 0 else suffix) * nums[n - 1 - i]
            result = max(result, prefix, suffix)

        return result
