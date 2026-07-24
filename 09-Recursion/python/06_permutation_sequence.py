class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = list(range(1, n + 1))
        fact = [1] * (n + 1)

        for i in range(2, n + 1):
            fact[i] = fact[i - 1] * i

        k -= 1
        res = []

        for i in range(n - 1, -1, -1):
            j = k // fact[i]
            k %= fact[i]
            res.append(str(nums[j]))
            nums.pop(j)

        return "".join(res)
