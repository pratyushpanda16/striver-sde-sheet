"""
Problem   : Two Sum
Link      : https://leetcode.com/problems/two-sum/
Difficulty: Easy
Approach  : Single-pass hash map storing value -> index.
Time      : O(n)
Space     : O(n)
"""

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i, num in enumerate(nums):
            need = target - num
            if need in seen:
                return [seen[need], i]
            seen[num] = i
        return []
