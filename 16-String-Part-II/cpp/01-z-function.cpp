class Solution {
public:
    vector<int> search(string pat, string txt) {
        string total = pat + "$" + txt;
        int n = total.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i > r) {
                l = r = i;
                while (r < n && total[r] == total[r - l])
                    r++;
                z[i] = r - l;
                r--;
            } else {
                int idx = i - l;
                if (i + z[idx] <= r) {
                    z[i] = z[idx];
                } else {
                    l = i;
                    while (r < n && total[r] == total[r - l])
                        r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }

        vector<int> ans;
        int m = pat.size();
        for (int i = 0; i < n; i++) {
            if (z[i] == m) {
                ans.push_back(i - m - 1);
            }
        }
        return ans;
    }
};
