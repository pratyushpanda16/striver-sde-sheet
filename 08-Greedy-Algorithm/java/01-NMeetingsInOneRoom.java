class Solution {
    public int maxMeetings(int[] start, int[] end) {
        int n = start.length;

        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        Arrays.sort(idx, (a, b) -> {
            if (end[a] == end[b]) {
                return start[a] - start[b];
            }
            return end[a] - end[b];
        });

        int count = 1;
        int lastEnd = end[idx[0]];

        for (int i = 1; i < n; i++) {
            if (start[idx[i]] > lastEnd) {
                count++;
                lastEnd = end[idx[i]];
            }
        }

        return count;
    }
}
