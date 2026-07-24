class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> freqMap;
        for (int c : candidates) {
            freqMap[c]++;
        }

        vector<pair<int, int>> pairs;
        for (auto& entry : freqMap) {
            pairs.push_back(entry);
        }

        vector<vector<int>> result;
        vector<int> current;
        backtrack(pairs, 0, target, current, result);
        return result;
    }

private:
    void backtrack(const vector<pair<int, int>>& pairs, int index, int remaining,
                   vector<int>& current, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        if (index == (int)pairs.size()) return;

        int value = pairs[index].first;
        int count = pairs[index].second;

        for (int copies = 0; copies <= count; copies++) {
            if (value * copies > remaining) break;

            for (int j = 0; j < copies; j++) {
                current.push_back(value);
            }
            backtrack(pairs, index + 1, remaining - value * copies, current, result);
            for (int j = 0; j < copies; j++) {
                current.pop_back();
            }
        }
    }
};
