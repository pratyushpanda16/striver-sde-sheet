class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n > 0) {
            string t = "";
            for (int i = 0; i < (int)s.size();) {
                int j = i;
                while (j < (int)s.size() && s[j] == s[i]) {
                    j++;
                }
                t += to_string(j - i);
                t += s[i];
                i = j;
            }
            s = t;
        }
        return s;
    }
};
