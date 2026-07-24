class Solution {
    vector<int> heap;

public:
    void initializeHeap() { heap.clear(); }

    void insert(int key) {
        heap.push_back(key);
        siftUp(heap.size() - 1);
    }

    void changeKey(int index, int newVal) {
        heap[index] = newVal;
        siftUp(index);
        siftDown(index);
    }

    void extractMax() {
        int last = heap.size() - 1;
        heap[0] = heap[last];
        heap.pop_back();
        if (!isEmpty()) siftDown(0);
    }

    bool isEmpty() const { return heap.empty(); }
    int getMax() const { return heap[0]; }
    int heapSize() const { return heap.size(); }

private:
    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[i] > heap[p]) {
                swap(heap[i], heap[p]);
                i = p;
            } else break;
        }
    }

    void siftDown(int i) {
        int n = heap.size();
        while (2 * i + 1 < n) {
            int l = 2 * i + 1, r = 2 * i + 2, big = l;
            if (r < n && heap[r] > heap[l]) big = r;
            if (heap[big] > heap[i]) {
                swap(heap[i], heap[big]);
                i = big;
            } else break;
        }
    }
};
