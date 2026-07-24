class Solution {
public:
    void sortStack(stack<int>& st) {
        if (st.empty()) return;

        int top = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, top);
    }

private:
    void insertSorted(stack<int>& st, int val) {
        if (st.empty() || st.top() <= val) {
            st.push(val);
            return;
        }

        int top = st.top();
        st.pop();
        insertSorted(st, val);
        st.push(top);
    }
};
