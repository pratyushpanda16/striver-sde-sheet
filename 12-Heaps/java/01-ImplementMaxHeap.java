class Solution {
    private ArrayList<Integer> heap = new ArrayList<>();

    public void initializeHeap() { heap.clear(); }

    public void insert(int key) {
        heap.add(key);
        siftUp(heap.size() - 1);
    }

    public void changeKey(int index, int newVal) {
        heap.set(index, newVal);
        siftUp(index);
        siftDown(index);
    }

    public void extractMax() {
        int last = heap.size() - 1;
        heap.set(0, heap.get(last));
        heap.remove(last);
        if (!isEmpty()) siftDown(0);
    }

    public boolean isEmpty()  { return heap.isEmpty(); }
    public int     getMax()   { return heap.get(0); }
    public int     heapSize() { return heap.size(); }

    private void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap.get(i) > heap.get(p)) { swap(i, p); i = p; }
            else break;
        }
    }

    private void siftDown(int i) {
        int n = heap.size();
        while (2 * i + 1 < n) {
            int l = 2 * i + 1, r = 2 * i + 2, big = l;
            if (r < n && heap.get(r) > heap.get(l)) big = r;
            if (heap.get(big) > heap.get(i)) { swap(i, big); i = big; }
            else break;
        }
    }

    private void swap(int a, int b) {
        int tmp = heap.get(a);
        heap.set(a, heap.get(b));
        heap.set(b, tmp);
    }
}
