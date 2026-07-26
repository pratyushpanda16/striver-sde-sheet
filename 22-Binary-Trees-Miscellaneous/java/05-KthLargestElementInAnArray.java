import java.util.*;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        int targetIndex = nums.length - k;
        return quickselect(nums, 0, nums.length - 1, targetIndex);
    }

    private int quickselect(int[] nums, int left, int right, int targetIndex) {
        while (left < right) {
            int pivotIndex = left + new Random().nextInt(right - left + 1);
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

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
