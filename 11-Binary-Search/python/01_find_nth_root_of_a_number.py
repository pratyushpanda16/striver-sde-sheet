class Solution:
    def NthRoot(self, N: int, M: int) -> int:
        low, high = 1, M

        def compute_power(base):
            res = 1
            for _ in range(N):
                res *= base
                if res > M:
                    return res
            return res

        while low <= high:
            mid = (low + high) // 2
            power = compute_power(mid)

            if power == M:
                return mid
            elif power < M:
                low = mid + 1
            else:
                high = mid - 1

        return -1
