class Solution:
    def celebrity(self, M: List[List[int]]) -> int:
        n = len(M)

        candidate = 0
        for i in range(1, n):
            if M[candidate][i] == 1:
                candidate = i

        for i in range(n):
            if i == candidate:
                continue
            if M[candidate][i] == 1 or M[i][candidate] == 0:
                return -1

        return candidate
