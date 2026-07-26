#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> smallHeap; // max heap
    priority_queue<int, vector<int>, greater<int>> largeHeap; // min heap

public:
    MedianFinder() {}

    void addNum(int num) {
        smallHeap.push(num);
        if (smallHeap.size() > largeHeap.size() + 1 ||
            (!largeHeap.empty() && smallHeap.top() > largeHeap.top())) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }

    double findMedian() {
        if (smallHeap.size() == largeHeap.size()) {
            return (smallHeap.top() + largeHeap.top()) / 2.0;
        } else if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
