class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }

        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && (int)res.size() < k; i--) {
            for (int num : bucket[i]) {
                res.push_back(num);
                if ((int)res.size() == k) break;
            }
        }

        return res;
    }
};
