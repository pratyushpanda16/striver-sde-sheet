class Solution:
    def eggDrop(self, n: int, k: int) -> int:
        dp = [0] * (n + 1)
        moves = 0
        while dp[n] < k:
            moves += 1
            for eggs in range(n, 0, -1):
                dp[eggs] = dp[eggs] + dp[eggs - 1] + 1
        return moves
