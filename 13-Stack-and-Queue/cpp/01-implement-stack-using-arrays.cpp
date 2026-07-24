class ArrayStack {
private:
    vector<int> stack;

public:
    ArrayStack() {}

    void push(int x) {
        stack.push_back(x);
    }

    int pop() {
        int val = stack.back();
        stack.pop_back();
        return val;
    }

    int top() {
        return stack.back();
    }

    bool isEmpty() {
        return stack.empty();
    }
};
