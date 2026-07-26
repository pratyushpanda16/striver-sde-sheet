#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }
        ans.push_back(freq.size());

        for (int i = k; i < n; i++) {
            int outgoing = nums[i - k];
            freq[outgoing]--;
            if (freq[outgoing] == 0) {
                freq.erase(outgoing);
            }

            freq[nums[i]]++;
            ans.push_back(freq.size());
        }

        return ans;
    }
};
