#include <vector>

using namespace std;

class Solution {
public:
    int LIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tails(n);
        int size = 0;

        for (int num : nums) {
            int lo = 0, hi = size;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (tails[mid] < num) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            tails[lo] = num;
            if (lo == size) size++;
        }

        return size;
    }
};
