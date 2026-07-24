class Solution {
public:
    int findMedian(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 1, high = 1e9;
        int required = (n * m) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countSmallerOrEqual(matrix, mid);

            if (count <= required) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }

private:
    int countSmallerOrEqual(const vector<vector<int>>& matrix, int x) {
        int count = 0;
        for (const auto& row : matrix) {
            count += upper_bound(row.begin(), row.end(), x) - row.begin();
        }
        return count;
    }
};
