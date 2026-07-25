class Solution {
public:
    vector<int> nextSmallerElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            result[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }

        return result;
    }
};
