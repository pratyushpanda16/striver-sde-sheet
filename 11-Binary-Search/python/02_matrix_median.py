import bisect

class Solution:
    def findMedian(self, matrix: List[List[int]]) -> int:
        n, m = len(matrix), len(matrix[0])
        low, high = 1, 10**9
        required = (n * m) // 2

        def count_smaller_or_equal(x):
            return sum(bisect.bisect_right(row, x) for row in matrix)

        while low <= high:
            mid = (low + high) // 2
            if count_smaller_or_equal(mid) <= required:
                low = mid + 1
            else:
                high = mid - 1

        return low
