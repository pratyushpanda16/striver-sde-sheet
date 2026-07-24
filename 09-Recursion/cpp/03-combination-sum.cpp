class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, 0, target, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int start, int remaining,
                   vector<int>& current, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < (int)candidates.size(); i++) {
            if (candidates[i] > remaining) break;
            current.push_back(candidates[i]);
            backtrack(candidates, i, remaining - candidates[i], current, result);
            current.pop_back();
        }
    }
};
