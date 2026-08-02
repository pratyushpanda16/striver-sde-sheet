#include <vector>

using namespace std;

class Solution {
public:
    int eggDrop(int n, int k) {
        vector<int> dp(n + 1, 0);
        int moves = 0;
        while (dp[n] < k) {
            moves++;
            for (int eggs = n; eggs >= 1; eggs--) {
                dp[eggs] = dp[eggs] + dp[eggs - 1] + 1;
            }
        }
        return moves;
    }
};
