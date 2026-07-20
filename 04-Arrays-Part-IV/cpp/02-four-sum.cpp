class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> quad;
        kSum(nums, 4, 0, (long long)target, quad, res);
        return res;
    }

private:
    void kSum(vector<int>& nums, int k, int start, long long target,
              vector<int>& quad, vector<vector<int>>& res) {
        if (k == 2) {
            int l = start, r = nums.size() - 1;
            while (l < r) {
                long long sum = (long long)nums[l] + nums[r];
                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    vector<int> tmp(quad);
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    res.push_back(tmp);
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
            return;
        }

        for (int i = start; i < (int)nums.size() - k + 1; i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            quad.push_back(nums[i]);
            kSum(nums, k - 1, i + 1, target - nums[i], quad, res);
            quad.pop_back();
        }
    }
};
