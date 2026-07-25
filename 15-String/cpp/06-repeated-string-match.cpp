class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        vector<bool> charInA(26, false);
        for (char c : a) charInA[c - 'a'] = true;
        for (char c : b) {
            if (!charInA[c - 'a']) return -1;
        }

        int minReps = (b.size() + a.size() - 1) / a.size();
        string repeated = "";
        for (int i = 0; i < minReps; i++) repeated += a;

        if (repeated.find(b) != string::npos) return minReps;

        repeated += a;
        if (repeated.find(b) != string::npos) return minReps + 1;

        return -1;
    }
};
