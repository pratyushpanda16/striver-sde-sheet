from collections import defaultdict
from typing import List

class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        ans = []
        freq = defaultdict(int)
        n = len(nums)

        for i in range(k):
            freq[nums[i]] += 1
        ans.append(len(freq))

        for i in range(k, n):
            outgoing = nums[i - k]
            freq[outgoing] -= 1
            if freq[outgoing] == 0:
                del freq[outgoing]

            freq[nums[i]] += 1
            ans.append(len(freq))

        return ans
