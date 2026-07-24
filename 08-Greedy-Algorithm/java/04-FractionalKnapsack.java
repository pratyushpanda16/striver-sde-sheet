class Solution {
    public double fractionalKnapsack(int[] val, int[] wt, long cap) {

        int n = val.length;

        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        Arrays.sort(idx, (a, b) -> Double.compare(
                (double) val[b] / wt[b],
                (double) val[a] / wt[a]
        ));

        double ans = 0.0;
        long currWeight = 0;

        for (int i = 0; i < n; i++) {

            int id = idx[i];

            if (currWeight + wt[id] <= cap) {
                currWeight += wt[id];
                ans += val[id];
            } else {
                long remain = cap - currWeight;
                ans += ((double) val[id] / wt[id]) * remain;
                break;
            }
        }

        return ans;
    }
}
