class Solution {
    public int maxProduct(int[] nums) {
        int result = nums[0];
        int prefix = 0;
        int suffix = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            prefix = (prefix == 0 ? 1 : prefix) * nums[i];
            suffix = (suffix == 0 ? 1 : suffix) * nums[n - 1 - i];
            result = Math.max(result, Math.max(prefix, suffix));
        }

        return result;
    }
}
