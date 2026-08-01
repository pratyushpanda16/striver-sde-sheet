#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumIncreasingSubsequence(vector<int>& arr, int n) {
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }

        int maxSum = arr[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && dp[j] + arr[i] > dp[i]) {
                    dp[i] = dp[j] + arr[i];
                }
            }
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};
