/*
 * Problem   : Two Sum
 * Link      : https://leetcode.com/problems/two-sum/
 * Difficulty: Easy
 * Approach  : Single-pass hash map storing value -> index.
 * Time      : O(n)
 * Space     : O(n)
 */

import java.util.HashMap;
import java.util.Map;

public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int need = target - nums[i];
            if (seen.containsKey(need)) {
                return new int[]{seen.get(need), i};
            }
            seen.put(nums[i], i);
        }
        return new int[]{};
    }
}
