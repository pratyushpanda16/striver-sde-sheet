class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<long long, int> map;

        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];

            if (sum == k) {
                maxLen = i + 1;
            }

            long long rem = sum - k;

            if (map.count(rem)) {
                maxLen = max(maxLen, i - map[rem]);
            }

            if (!map.count(sum)) {
                map[sum] = i;
            }
        }

        return maxLen;
    }
};
