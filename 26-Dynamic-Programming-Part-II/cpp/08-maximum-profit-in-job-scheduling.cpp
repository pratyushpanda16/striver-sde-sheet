#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int currStart = jobs[i - 1][0];
            int currProfit = jobs[i - 1][2];

            int lo = 0, hi = i - 1, idx = 0;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (jobs[mid - 1][1] <= currStart) {
                    idx = mid;
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }

            dp[i] = max(dp[i - 1], dp[idx] + currProfit);
        }

        return dp[n];
    }
};
