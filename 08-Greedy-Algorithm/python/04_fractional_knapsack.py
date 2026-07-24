class Solution:
    def fractionalKnapsack(self, val: List[int], wt: List[int], cap: int) -> float:
        n = len(val)
        items = [(val[i], wt[i], val[i] / wt[i]) for i in range(n)]
        items.sort(key=lambda x: x[2], reverse=True)

        ans = 0.0
        curr_weight = 0

        for v, w, r in items:
            if curr_weight + w <= cap:
                curr_weight += w
                ans += v
            else:
                remain = cap - curr_weight
                ans += r * remain
                break

        return ans
