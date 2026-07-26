import random
from typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        target_index = len(nums) - k
        left, right = 0, len(nums) - 1

        while left < right:
            pivot_index = random.randint(left, right)
            pivot = nums[pivot_index]

            lo, hi, i = left, right, left
            while i <= hi:
                if nums[i] < pivot:
                    nums[i], nums[lo] = nums[lo], nums[i]
                    lo += 1
                    i += 1
                elif nums[i] > pivot:
                    nums[i], nums[hi] = nums[hi], nums[i]
                    hi -= 1
                else:
                    i += 1

            if target_index < lo:
                right = lo - 1
            elif target_index > hi:
                left = hi + 1
            else:
                return pivot

        return nums[left]
