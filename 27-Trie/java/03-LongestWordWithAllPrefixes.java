import java.util.*;

class Solution {
    public String completeString(List<String> nums) {
        Set<String> set = new HashSet<>(nums);
        String best = "";

        for (String word : nums) {
            boolean isComplete = true;
            for (int i = 1; i < word.length(); i++) {
                if (!set.contains(word.substring(0, i))) {
                    isComplete = false;
                    break;
                }
            }

            if (isComplete) {
                if (word.length() > best.length() ||
                    (word.length() == best.length() && word.compareTo(best) < 0)) {
                    best = word;
                }
            }
        }

        return best.isEmpty() ? "None" : best;
    }
}
