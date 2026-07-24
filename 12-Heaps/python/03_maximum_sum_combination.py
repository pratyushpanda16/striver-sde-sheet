import heapq

class Solution:
    def maxSumCombinations(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        nums1.sort()
        nums2.sort()
        n = len(nums1)

        result = []
        max_heap = []
        visited = set()

        i, j = n - 1, n - 1
        heapq.heappush(max_heap, (-(nums1[i] + nums2[j]), i, j))
        visited.add((i, j))

        for _ in range(k):
            val, r, c = heapq.heappop(max_heap)
            result.append(-val)

            if r - 1 >= 0 and (r - 1, c) not in visited:
                heapq.heappush(max_heap, (-(nums1[r - 1] + nums2[c]), r - 1, c))
                visited.add((r - 1, c))

            if c - 1 >= 0 and (r, c - 1) not in visited:
                heapq.heappush(max_heap, (-(nums1[r] + nums2[c - 1]), r, c - 1))
                visited.add((r, c - 1))

        return result
