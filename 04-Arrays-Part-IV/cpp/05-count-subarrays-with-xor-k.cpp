class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        int xorVal = 0;
        int count = 0;

        map[0] = 1;

        for (int num : nums) {
            xorVal ^= num;

            if (map.count(xorVal ^ k)) {
                count += map[xorVal ^ k];
            }

            map[xorVal]++;
        }

        return count;
    }
};
