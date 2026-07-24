class ArrayQueue:
    def __init__(self):
        self.queue = []
        self.front = 0

    def push(self, x: int) -> None:
        self.queue.append(x)

    def pop(self) -> int:
        val = self.queue[self.front]
        self.front += 1
        return val

    def peek(self) -> int:
        return self.queue[self.front]

    def isEmpty(self) -> bool:
        return self.front >= len(self.queue)
