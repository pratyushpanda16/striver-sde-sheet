class Solution {
    public int findMaximumXOR(int[] nums) {
        int[][] trie = new int[31 * nums.length + 1][2];
        int trieSize = 1;

        for (int[] node : trie) {
            node[0] = -1;
            node[1] = -1;
        }

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
            maxXor = Math.max(maxXor, currentXor);
        }

        return maxXor;
    }
}
