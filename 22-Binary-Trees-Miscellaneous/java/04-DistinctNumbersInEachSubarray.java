import java.util.*;

class Solution {
    public List<Integer> distinctNumbers(int[] nums, int k) {
        List<Integer> ans = new ArrayList<>();
        Map<Integer, Integer> freq = new HashMap<>();
        int n = nums.length;

        for (int i = 0; i < k; i++) {
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
        }
        ans.add(freq.size());

        for (int i = k; i < n; i++) {
            int outgoing = nums[i - k];
            freq.put(outgoing, freq.get(outgoing) - 1);
            if (freq.get(outgoing) == 0) {
                freq.remove(outgoing);
            }

            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
            ans.add(freq.size());
        }

        return ans;
    }
}
