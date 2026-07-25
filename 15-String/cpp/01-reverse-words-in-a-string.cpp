class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();

        int write = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (write > 0) s[write++] = ' ';

                int wordStart = write;
                while (i < n && s[i] != ' ') {
                    s[write++] = s[i++];
                }

                reverse(s.begin() + wordStart, s.begin() + write);
            }
        }

        s.resize(write);
        return s;
    }
};
