class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty()) return 0;

        int n = haystack.length();
        int m = needle.length();

        int[] lps = new int[m];
        int len = 0;

        for (int i = 1; i < m;) {
            if (needle.charAt(i) == needle.charAt(len)) {
                lps[i++] = ++len;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int i = 0, j = 0;

        while (i < n) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
                if (j == m) return i - j;
            } else if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return -1;
    }
}
