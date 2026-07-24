class Solution:
    def sortStack(self, st: List[int]) -> None:
        if not st:
            return

        top = st.pop()
        self.sortStack(st)
        self._insert_sorted(st, top)

    def _insert_sorted(self, st: List[int], val: int) -> None:
        if not st or st[-1] <= val:
            st.append(val)
            return

        top = st.pop()
        self._insert_sorted(st, val)
        st.append(top)
