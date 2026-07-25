class Solution {
    public int repeatedStringMatch(String a, String b) {
        boolean[] charInA = new boolean[26];
        for (char c : a.toCharArray()) {
            charInA[c - 'a'] = true;
        }
        for (char c : b.toCharArray()) {
            if (!charInA[c - 'a']) return -1;
        }

        int minReps = (b.length() + a.length() - 1) / a.length();

        StringBuilder repeated = new StringBuilder();
        for (int i = 0; i < minReps; i++) {
            repeated.append(a);
        }

        if (repeated.toString().contains(b)) {
            return minReps;
        }

        repeated.append(a);
        if (repeated.toString().contains(b)) {
            return minReps + 1;
        }

        return -1;
    }
}
