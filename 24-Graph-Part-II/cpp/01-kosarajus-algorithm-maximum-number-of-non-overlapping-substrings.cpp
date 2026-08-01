#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> left(26, n), right(26, -1);
        for (int i = 0; i < n; ++i) {
            left[s[i] - 'a'] = min(left[s[i] - 'a'], i);
            right[s[i] - 'a'] = i;
        }

        vector<string> res;
        int r = -1;

        for (int i = 0; i < n; ++i) {
            if (i != left[s[i] - 'a']) continue;
            int newR = right[s[i] - 'a'];
            for (int j = i + 1; j <= newR; ++j) {
                if (left[s[j] - 'a'] < i) {
                    newR = n;
                    break;
                }
                newR = max(newR, right[s[j] - 'a']);
            }
            if (newR < n && (i > r || newR < right[s[r] - 'a'])) {
                if (i > r) res.push_back(s.substr(i, newR - i + 1));
                else res.back() = s.substr(i, newR - i + 1);
                r = newR;
            }
        }
        return res;
    }
};
