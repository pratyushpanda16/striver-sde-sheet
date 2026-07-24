class Solution:
    def __init__(self):
        self.heap = []

    def initializeHeap(self):
        self.heap.clear()

    def insert(self, key: int):
        self.heap.append(key)
        self._sift_up(len(self.heap) - 1)

    def changeKey(self, index: int, newVal: int):
        self.heap[index] = newVal
        self._sift_up(index)
        self._sift_down(index)

    def extractMax(self):
        last = len(self.heap) - 1
        self.heap[0] = self.heap[last]
        self.heap.pop()
        if not self.isEmpty():
            self._sift_down(0)

    def isEmpty(self) -> bool:
        return len(self.heap) == 0

    def getMax(self) -> int:
        return self.heap[0]

    def heapSize(self) -> int:
        return len(self.heap)

    def _sift_up(self, i: int):
        while i > 0:
            p = (i - 1) // 2
            if self.heap[i] > self.heap[p]:
                self.heap[i], self.heap[p] = self.heap[p], self.heap[i]
                i = p
            else:
                break

    def _sift_down(self, i: int):
        n = len(self.heap)
        while 2 * i + 1 < n:
            l, r = 2 * i + 1, 2 * i + 2
            big = l
            if r < n and self.heap[r] > self.heap[l]:
                big = r
            if self.heap[big] > self.heap[i]:
                self.heap[i], self.heap[big] = self.heap[big], self.heap[i]
                i = big
            else:
                break
