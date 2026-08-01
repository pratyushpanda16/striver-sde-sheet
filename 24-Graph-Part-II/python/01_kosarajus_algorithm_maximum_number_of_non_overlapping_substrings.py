from typing import List

class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        n = len(s)
        left = [n] * 26
        right = [-1] * 26

        for i, ch in enumerate(s):
            idx = ord(ch) - ord('a')
            left[idx] = min(left[idx], i)
            right[idx] = i

        res = []
        r = -1

        for i in range(n):
            idx = ord(s[i]) - ord('a')
            if i != left[idx]:
                continue
            newR = right[idx]
            valid = True
            j = i + 1
            while j <= newR:
                j_idx = ord(s[j]) - ord('a')
                if left[j_idx] < i:
                    valid = False
                    break
                newR = max(newR, right[j_idx])
                j += 1

            if valid and newR < n and (i > r or newR < right[ord(s[r]) - ord('a')]):
                if i > r:
                    res.append(s[i:newR + 1])
                else:
                    res[-1] = s[i:newR + 1]
                r = newR

        return res
