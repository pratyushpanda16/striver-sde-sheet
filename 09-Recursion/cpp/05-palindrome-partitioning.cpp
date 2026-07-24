class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int end = 0; end < n; end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                    dp[start][end] = true;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, dp, path, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, const vector<vector<bool>>& dp,
                   vector<string>& path, vector<vector<string>>& result) {
        if (start == (int)s.length()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < (int)s.length(); end++) {
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, dp, path, result);
                path.pop_back();
            }
        }
    }
};
