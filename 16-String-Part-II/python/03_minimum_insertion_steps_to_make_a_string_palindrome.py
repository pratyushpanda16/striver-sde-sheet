class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        memo = {}

        def dfs(i, j):
            if i >= j:
                return 0
            if (i, j) in memo:
                return memo[(i, j)]

            if s[i] == s[j]:
                res = dfs(i + 1, j - 1)
            else:
                res = min(dfs(i + 1, j), dfs(i, j - 1)) + 1

            memo[(i, j)] = res
            return res

        return dfs(0, n - 1)
