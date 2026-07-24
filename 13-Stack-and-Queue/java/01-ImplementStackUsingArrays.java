class ArrayStack {
    private int[] stack;
    private int size;
    private static final int INITIAL_CAPACITY = 16;

    public ArrayStack() {
        stack = new int[INITIAL_CAPACITY];
        size = 0;
    }

    public void push(int x) {
        if (size == stack.length) {
            int[] newStack = new int[stack.length * 2];
            System.arraycopy(stack, 0, newStack, 0, size);
            stack = newStack;
        }
        stack[size++] = x;
    }

    public int pop() {
        return stack[--size];
    }

    public int top() {
        return stack[size - 1];
    }

    public boolean isEmpty() {
        return size == 0;
    }
}
