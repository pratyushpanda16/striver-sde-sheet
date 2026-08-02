#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int sum = 1; sum <= target; sum++) {
                bool notTake = dp[i - 1][sum];
                bool take = false;

                if (arr[i - 1] <= sum) {
                    take = dp[i - 1][sum - arr[i - 1]];
                }

                dp[i][sum] = take || notTake;
            }
        }

        return dp[n][target];
    }
};
