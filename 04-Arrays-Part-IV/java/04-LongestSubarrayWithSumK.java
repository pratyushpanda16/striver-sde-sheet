class Solution {
    public int longestSubarray(int[] nums, int k) {
        HashMap<Long, Integer> map = new HashMap<>();

        long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];

            if (sum == k) {
                maxLen = i + 1;
            }

            long rem = sum - k;

            if (map.containsKey(rem)) {
                maxLen = Math.max(maxLen, i - map.get(rem));
            }

            map.putIfAbsent(sum, i);
        }

        return maxLen;
    }
}
