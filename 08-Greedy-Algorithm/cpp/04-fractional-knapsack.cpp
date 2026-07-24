class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, long long cap) {
        int n = val.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return (double)val[b] / wt[b] < (double)val[a] / wt[a];
        });

        double ans = 0.0;
        long long currWeight = 0;

        for (int i = 0; i < n; i++) {
            int id = idx[i];
            if (currWeight + wt[id] <= cap) {
                currWeight += wt[id];
                ans += val[id];
            } else {
                long long remain = cap - currWeight;
                ans += ((double)val[id] / wt[id]) * remain;
                break;
            }
        }

        return ans;
    }
};
