class Solution:
    def subarraysWithXorK(self, nums: List[int], k: int) -> int:
        map = {0: 1}
        xor = 0
        count = 0

        for num in nums:
            xor ^= num
            count += map.get(xor ^ k, 0)
            map[xor] = map.get(xor, 0) + 1

        return count
