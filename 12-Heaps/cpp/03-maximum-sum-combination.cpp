class Solution {
public:
    vector<int> maxSumCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size();
        vector<int> result;

        priority_queue<pair<int, pair<int, int>>> maxHeap;
        set<pair<int, int>> visited;

        int i = n - 1, j = n - 1;
        maxHeap.push({nums1[i] + nums2[j], {i, j}});
        visited.insert({i, j});

        for (int idx = 0; idx < k; idx++) {
            auto top = maxHeap.top();
            maxHeap.pop();
            result.push_back(top.first);

            int r = top.second.first;
            int c = top.second.second;

            if (r - 1 >= 0 && !visited.count({r - 1, c})) {
                maxHeap.push({nums1[r - 1] + nums2[c], {r - 1, c}});
                visited.insert({r - 1, c});
            }

            if (c - 1 >= 0 && !visited.count({r, c - 1})) {
                maxHeap.push({nums1[r] + nums2[c - 1], {r, c - 1}});
                visited.insert({r, c - 1});
            }
        }

        return result;
    }
};
