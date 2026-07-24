class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (end[a] == end[b]) return start[a] < start[b];
            return end[a] < end[b];
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
};
