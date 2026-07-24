class Solution {
public:
    int kthLargestElement(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > (size_t)k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
