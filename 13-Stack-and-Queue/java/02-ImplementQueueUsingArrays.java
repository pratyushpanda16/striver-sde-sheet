class ArrayQueue {
    private int[] queue;
    private int front, size;
    private static final int INITIAL_CAPACITY = 16;

    public ArrayQueue() {
        queue = new int[INITIAL_CAPACITY];
        front = 0;
        size = 0;
    }

    public void push(int x) {
        if (size == queue.length) {
            int[] newQueue = new int[queue.length * 2];
            for (int i = 0; i < size; i++)
                newQueue[i] = queue[(front + i) % queue.length];
            queue = newQueue;
            front = 0;
        }
        queue[(front + size) % queue.length] = x;
        size++;
    }

    public int pop() {
        int val = queue[front];
        front = (front + 1) % queue.length;
        size--;
        return val;
    }

    public int peek() {
        return queue[front];
    }

    public boolean isEmpty() {
        return size == 0;
    }
}
