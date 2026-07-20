class Solution {
    public int subarraysWithXorK(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();

        int xor = 0;
        int count = 0;

        map.put(0, 1);

        for (int num : nums) {
            xor ^= num;

            count += map.getOrDefault(xor ^ k, 0);

            map.put(xor, map.getOrDefault(xor, 0) + 1);
        }

        return count;
    }
}
