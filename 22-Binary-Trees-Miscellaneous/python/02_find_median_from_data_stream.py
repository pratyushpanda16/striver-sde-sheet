import heapq

class MedianFinder:

    def __init__(self):
        self.small_heap = []  # max heap (stored as negative values)
        self.large_heap = []  # min heap

    def addNum(self, num: int) -> None:
        heapq.heappush(self.small_heap, -num)
        if len(self.small_heap) - len(self.large_heap) > 1 or (
            self.large_heap and (-self.small_heap[0]) > self.large_heap[0]
        ):
            heapq.heappush(self.large_heap, -heapq.heappop(self.small_heap))
        if len(self.large_heap) - len(self.small_heap) > 1:
            heapq.heappush(self.small_heap, -heapq.heappop(self.large_heap))

    def findMedian(self) -> float:
        if len(self.small_heap) == len(self.large_heap):
            return (-self.small_heap[0] + self.large_heap[0]) / 2.0
        elif len(self.small_heap) > len(self.large_heap):
            return float(-self.small_heap[0])
        else:
            return float(self.large_heap[0])


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
