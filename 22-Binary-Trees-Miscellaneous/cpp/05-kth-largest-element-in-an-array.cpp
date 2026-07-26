#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int quickselect(vector<int>& nums, int left, int right, int targetIndex) {
        while (left < right) {
            int pivotIndex = left + rand() % (right - left + 1);
            int pivot = nums[pivotIndex];

            int lo = left, hi = right, i = left;
            while (i <= hi) {
                if (nums[i] < pivot) {
                    swap(nums, i, lo);
                    lo++;
                    i++;
                } else if (nums[i] > pivot) {
                    swap(nums, i, hi);
                    hi--;
                } else {
                    i++;
                }
            }

            if (targetIndex < lo) {
                right = lo - 1;
            } else if (targetIndex > hi) {
                left = hi + 1;
            } else {
                return pivot;
            }
        }
        return nums[left];
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int targetIndex = nums.size() - k;
        return quickselect(nums, 0, nums.size() - 1, targetIndex);
    }
};
