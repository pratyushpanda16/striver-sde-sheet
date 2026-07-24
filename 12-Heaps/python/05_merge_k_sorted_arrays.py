import heapq

class Solution:
    def mergeKSortedArrays(self, arr: List[List[int]], k: int) -> List[int]:
        result = []
        min_heap = []

        for i in range(k):
            heapq.heappush(min_heap, (arr[i][0], i, 0))

        while min_heap:
            val, row, col = heapq.heappop(min_heap)
            result.append(val)

            if col + 1 < len(arr[row]):
                heapq.heappush(min_heap, (arr[row][col + 1], row, col + 1))

        return result
