class Node:
    def __init__(self):
        self.children = [None] * 26

class Solution:
    def countDistinctSubstring(self, s: str) -> int:
        root = Node()
        count = 0
        n = len(s)

        for i in range(n):
            curr = root
            for j in range(i, n):
                idx = ord(s[j]) - ord('a')
                if not curr.children[idx]:
                    curr.children[idx] = Node()
                    count += 1
                curr = curr.children[idx]

        return count + 1
