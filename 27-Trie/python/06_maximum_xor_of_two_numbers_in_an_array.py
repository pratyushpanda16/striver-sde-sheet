from typing import List

class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        n = len(nums)
        trie = [[-1, -1] for _ in range(31 * n + 1)]
        trie_size = 1

        for num in nums:
            node = 0
            for k in range(30, -1, -1):
                bit = (num >> k) & 1
                if trie[node][bit] == -1:
                    trie[node][bit] = trie_size
                    trie_size += 1
                node = trie[node][bit]

        max_xor = 0
        for num in nums:
            node = 0
            current_xor = 0
            for k in range(30, -1, -1):
                bit = (num >> k) & 1
                opposite_bit = 1 - bit

                if trie[node][opposite_bit] != -1:
                    current_xor |= (1 << k)
                    node = trie[node][opposite_bit]
                else:
                    node = trie[node][bit]
            max_xor = max(max_xor, current_xor)

        return max_xor
