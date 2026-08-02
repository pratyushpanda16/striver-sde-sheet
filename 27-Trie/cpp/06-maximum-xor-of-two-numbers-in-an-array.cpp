#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> trie(31 * n + 1, vector<int>(2, -1));
        int trieSize = 1;

        for (int num : nums) {
            int node = 0;
            for (int k = 30; k >= 0; k--) {
                int bit = (num >> k) & 1;
                if (trie[node][bit] == -1) {
                    trie[node][bit] = trieSize++;
                }
                node = trie[node][bit];
            }
        }

        int maxXor = 0;
        for (int num : nums) {
            int node = 0;
            int currentXor = 0;
            for (int k = 30; k >= 0; k--) {
                int bit = (num >> k) & 1;
                int oppositeBit = 1 - bit;

                if (trie[node][oppositeBit] != -1) {
                    currentXor |= (1 << k);
                    node = trie[node][oppositeBit];
                } else {
                    node = trie[node][bit];
                }
            }
            maxXor = max(maxXor, currentXor);
        }

        return maxXor;
    }
};
