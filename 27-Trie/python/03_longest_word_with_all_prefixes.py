from typing import List

class Solution:
    def completeString(self, nums: List[str]) -> str:
        word_set = set(nums)
        best = ""

        for word in nums:
            is_complete = True
            for i in range(1, len(word)):
                if word[:i] not in word_set:
                    is_complete = False
                    break

            if is_complete:
                if len(word) > len(best) or (len(word) == len(best) and word < best):
                    best = word

        return best if best else "None"
