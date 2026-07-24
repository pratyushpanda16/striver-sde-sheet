class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> result(nums1.size());
        for (int i = 0; i < (int)nums1.size(); i++) {
            result[i] = nextGreater.count(nums1[i]) ? nextGreater[nums1[i]] : -1;
        }
        return result;
    }
};
