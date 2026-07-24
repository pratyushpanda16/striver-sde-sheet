class Solution {
    public int aggressiveCows(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;

        int low = 1;
        int high = nums[n - 1] - nums[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(nums, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    private boolean canPlaceCows(int[] nums, int k, int minDist) {
        int cowsPlaced = 1;
        int lastPosition = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - lastPosition >= minDist) {
                cowsPlaced++;
                lastPosition = nums[i];
            }

            if (cowsPlaced >= k) {
                return true;
            }
        }

        return false;
    }
}
