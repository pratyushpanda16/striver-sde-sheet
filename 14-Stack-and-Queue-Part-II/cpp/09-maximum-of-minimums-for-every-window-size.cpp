class Solution {
public:
    vector<int> maxOfMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            int windowSize = right[i] - left[i] - 1;
            int idx = windowSize - 1;
            result[idx] = max(result[idx], arr[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            result[i] = max(result[i], result[i + 1]);
        }

        return result;
    }
};
