class Solution:
    def longestPalindrome(self, s: str) -> str:
        t = "#" + "#".join(s) + "#"
        n = len(t)
        p = [0] * n
        l, r = 0, 0

        for i in range(n):
            if i < r:
                p[i] = min(r - i, p[l + (r - i)])
            while i + p[i] + 1 < n and i - p[i] - 1 >= 0 and t[i + p[i] + 1] == t[i - p[i] - 1]:
                p[i] += 1
            if i + p[i] > r:
                l = i - p[i]
                r = i + p[i]

        max_len, center_idx = 0, 0
        for i in range(n):
            if p[i] > max_len:
                max_len = p[i]
                center_idx = i

        start = (center_idx - max_len) // 2
        return s[start:start + max_len]
