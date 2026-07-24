class Solution {
    public void sortStack(Stack<Integer> st) {
        if (st.isEmpty()) return;

        int top = st.pop();
        sortStack(st);
        insertSorted(st, top);
    }

    private void insertSorted(Stack<Integer> st, int val) {
        if (st.isEmpty() || st.peek() <= val) {
            st.push(val);
            return;
        }

        int top = st.pop();
        insertSorted(st, val);
        st.push(top);
    }
}
