class Solution:
    def longestSubarray(self, nums: List[int], k: int) -> int:
        map = {}
        sum_val = 0
        max_len = 0

        for i in range(len(nums)):
            sum_val += nums[i]

            if sum_val == k:
                max_len = i + 1

            rem = sum_val - k

            if rem in map:
                max_len = max(max_len, i - map[rem])

            if sum_val not in map:
                map[sum_val] = i

        return max_len
