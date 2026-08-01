from typing import List

class Solution:
    def shortestDistance(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        inf = 10**9

        for i in range(n):
            for j in range(n):
                if matrix[i][j] == -1:
                    matrix[i][j] = inf

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if matrix[i][k] + matrix[k][j] < matrix[i][j]:
                        matrix[i][j] = matrix[i][k] + matrix[k][j]

        for i in range(n):
            for j in range(n):
                if matrix[i][j] == inf:
                    matrix[i][j] = -1
