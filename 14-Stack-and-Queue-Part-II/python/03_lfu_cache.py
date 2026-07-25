from collections import defaultdict

class Node:
    def __init__(self, key: int = 0, val: int = 0):
        self.key = key
        self.val = val
        self.freq = 1
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.left = Node()
        self.right = Node()
        self.left.next = self.right
        self.right.prev = self.left
        self.size = 0

    def push_right(self, node):
        prev = self.right.prev
        prev.next = node
        node.prev = prev
        node.next = self.right
        self.right.prev = node
        self.size += 1

    def pop(self, node):
        prev, nxt = node.prev, node.next
        prev.next = nxt
        nxt.prev = prev
        node.prev = None
        node.next = None
        self.size -= 1

    def pop_left(self):
        node = self.left.next
        self.pop(node)
        return node

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.lfu_count = 0
        self.node_map = {}
        self.list_map = defaultdict(DoublyLinkedList)

    def _counter(self, node):
        count = node.freq
        self.list_map[count].pop(node)

        if count == self.lfu_count and self.list_map[count].size == 0:
            self.lfu_count += 1

        node.freq += 1
        self.list_map[node.freq].push_right(node)

    def get(self, key: int) -> int:
        if key not in self.node_map:
            return -1
        node = self.node_map[key]
        self._counter(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        if key in self.node_map:
            node = self.node_map[key]
            node.val = value
            self._counter(node)
            return

        if len(self.node_map) == self.capacity:
            to_remove = self.list_map[self.lfu_count].pop_left()
            del self.node_map[to_remove.key]

        node = Node(key, value)
        self.node_map[key] = node
        self.list_map[1].push_right(node)
        self.lfu_count = 1
