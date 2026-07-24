class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
        vector<int> result;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        for (int i = 0; i < k; i++) {
            minHeap.push({arr[i][0], i, 0});
        }

        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int val = top[0], row = top[1], col = top[2];

            result.push_back(val);

            if (col + 1 < (int)arr[row].size()) {
                minHeap.push({arr[row][col + 1], row, col + 1});
            }
        }

        return result;
    }
};
