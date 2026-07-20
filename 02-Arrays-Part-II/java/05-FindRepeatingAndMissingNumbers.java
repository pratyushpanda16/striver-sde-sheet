class Solution {
    public int[] findMissingRepeatingNumbers(int[] nums) {
        int n = nums.length;

        int xr = 0;
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        int number = xr & ~(xr - 1);

        int zero = 0, one = 0;

        for (int i = 0; i < n; i++) {
            if ((nums[i] & number) != 0) {
                one ^= nums[i];
            } else {
                zero ^= nums[i];
            }
        }

        for (int i = 1; i <= n; i++) {
            if ((i & number) != 0) {
                one ^= i;
            } else {
                zero ^= i;
            }
        }

        int cnt = 0;
        for (int val : nums) {
            if (val == zero) cnt++;
        }

        if (cnt == 2) {
            return new int[]{zero, one};
        }

        return new int[]{one, zero};
    }
}
