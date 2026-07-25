class Solution {
    public String reverseWords(String s) {
        char[] chars = s.toCharArray();
        int n = chars.length;

        reverse(chars, 0, n - 1);

        int write = 0;
        for (int i = 0; i < n; i++) {
            if (chars[i] != ' ') {
                if (write > 0) chars[write++] = ' ';

                int wordStart = write;
                while (i < n && chars[i] != ' ') {
                    chars[write++] = chars[i++];
                }

                reverse(chars, wordStart, write - 1);
            }
        }

        return new String(chars, 0, write);
    }

    private void reverse(char[] chars, int left, int right) {
        while (left < right) {
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
    }
}
