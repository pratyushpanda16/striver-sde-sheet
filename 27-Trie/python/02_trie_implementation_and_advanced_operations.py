class Node:
    def __init__(self):
        self.children = [None] * 26
        self.end_count = 0
        self.prefix_count = 0

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            idx = ord(c) - ord('a')
            if not curr.children[idx]:
                curr.children[idx] = Node()
            curr = curr.children[idx]
            curr.prefix_count += 1
        curr.end_count += 1

    def countWordsEqualTo(self, word: str) -> int:
        curr = self.root
        for c in word:
            idx = ord(c) - ord('a')
            if not curr.children[idx]:
                return 0
            curr = curr.children[idx]
        return curr.end_count

    def countWordsStartingWith(self, prefix: str) -> int:
        curr = self.root
        for c in prefix:
            idx = ord(c) - ord('a')
            if not curr.children[idx]:
                return 0
            curr = curr.children[idx]
        return curr.prefix_count

    def erase(self, word: str) -> None:
        if self.countWordsEqualTo(word) == 0:
            return
        curr = self.root
        for c in word:
            idx = ord(c) - ord('a')
            curr = curr.children[idx]
            curr.prefix_count -= 1
        curr.end_count -= 1
