class Solution:
    def findMissingRepeatingNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)

        xr = 0
        for i in range(n):
            xr ^= nums[i]
            xr ^= (i + 1)

        number = xr & ~(xr - 1)

        zero, one = 0, 0

        for i in range(n):
            if nums[i] & number:
                one ^= nums[i]
            else:
                zero ^= nums[i]

        for i in range(1, n + 1):
            if i & number:
                one ^= i
            else:
                zero ^= i

        cnt = sum(1 for val in nums if val == zero)

        if cnt == 2:
            return [zero, one]

        return [one, zero]
