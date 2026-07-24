class Solution {
public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        sort(Jobs.begin(), Jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        int maxDeadline = 0;
        for (const auto& job : Jobs) {
            maxDeadline = max(maxDeadline, job[1]);
        }

        vector<int> slot(maxDeadline + 1, -1);
        int countJobs = 0, totalProfit = 0;

        for (int i = 0; i < (int)Jobs.size(); i++) {
            int deadline = Jobs[i][1];
            int profit = Jobs[i][2];

            for (int j = deadline; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    totalProfit += profit;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};
