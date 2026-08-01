#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }

        return dp[W];
    }
};
