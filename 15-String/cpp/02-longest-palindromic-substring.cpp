class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (char c : s) {
            t += c;
            t += '#';
        }

        int n = t.size();
        vector<int> p(n, 0);
        int l = 0, r = 0;

        for (int i = 0; i < n; i++) {
            if (i < r) p[i] = min(r - i, p[l + (r - i)]);
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }

        int maxLen = 0, centerIdx = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIdx = i;
            }
        }

        int start = (centerIdx - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};
