from typing import List

class Solution:
    def powerSet(self, nums: List[int]) -> List[List[int]]:
        result = []
        n = len(nums)
        total = 1 << n

        for mask in range(total):
            subset = []
            for i in range(n):
                if mask & (1 << i):
                    subset.append(nums[i])
            result.append(subset)

        return result
