class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index == (int)nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < (int)nums.size(); i++) {
            swap(nums[index], nums[i]);
            backtrack(nums, index + 1, result);
            swap(nums[index], nums[i]);
        }
    }
};
