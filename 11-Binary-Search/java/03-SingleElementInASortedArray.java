public class Solution {
    public int singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;

        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] != nums[m ^ 1]) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return nums[l];
    }
}
