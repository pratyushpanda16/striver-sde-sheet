class Solution {
    vector<vector<int>> memo;

public:
    int minInsertions(string s) {
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));
        return dfs(0, n - 1, s);
    }

private:
    int dfs(int i, int j, const string& s) {
        if (i >= j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == s[j]) {
            return memo[i][j] = dfs(i + 1, j - 1, s);
        } else {
            return memo[i][j] = min(dfs(i + 1, j, s), dfs(i, j - 1, s)) + 1;
        }
    }
};
