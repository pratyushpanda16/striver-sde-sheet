class ArrayQueue {
private:
    vector<int> queue;
    int front;

public:
    ArrayQueue() : front(0) {}

    void push(int x) {
        queue.push_back(x);
    }

    int pop() {
        int val = queue[front++];
        return val;
    }

    int peek() {
        return queue[front];
    }

    bool isEmpty() {
        return front >= (int)queue.size();
    }
};
