#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string completeString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string best = "";

        for (const string& word : nums) {
            bool isComplete = true;
            for (int i = 1; i < word.length(); i++) {
                if (!st.count(word.substr(0, i))) {
                    isComplete = false;
                    break;
                }
            }

            if (isComplete) {
                if (word.length() > best.length() ||
                    (word.length() == best.length() && word < best)) {
                    best = word;
                }
            }
        }

        return best.empty() ? "None" : best;
    }
};
