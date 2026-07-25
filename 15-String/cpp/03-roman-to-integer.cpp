class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int current = values[s[i]];
            if (i < n - 1 && current < values[s[i + 1]]) {
                result -= current;
            } else {
                result += current;
            }
        }

        return result;
    }
};
