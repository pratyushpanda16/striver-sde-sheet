from typing import List

class Trie:
    def __init__(self):
        self.children = [None, None]

    def insert(self, x: int) -> None:
        node = self
        for i in range(30, -1, -1):
            v = (x >> i) & 1
            if not node.children[v]:
                node.children[v] = Trie()
            node = node.children[v]

    def search(self, x: int) -> int:
        node = self
        ans = 0
        for i in range(30, -1, -1):
            v = (x >> i) & 1
            if node.children[v ^ 1]:
                ans |= (1 << i)
                node = node.children[v ^ 1]
            elif node.children[v]:
                node = node.children[v]
            else:
                return -1
        return ans

class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        nums.sort()
        n = len(queries)
        idx = list(range(n))
        idx.sort(key=lambda i: queries[i][1])

        ans = [-1] * n
        trie = Trie()
        j = 0

        for i in idx:
            x, m = queries[i][0], queries[i][1]
            while j < len(nums) and nums[j] <= m:
                trie.insert(nums[j])
                j += 1
            ans[i] = trie.search(x)

        return ans
