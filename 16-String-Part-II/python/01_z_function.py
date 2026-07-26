class Solution:
    def search(self, pat: str, txt: str) -> List[int]:
        total = pat + "$" + txt
        n = len(total)
        z = [0] * n
        l, r = 0, 0

        for i in range(1, n):
            if i > r:
                l = r = i
                while r < n and total[r] == total[r - l]:
                    r += 1
                z[i] = r - l
                r -= 1
            else:
                idx = i - l
                if i + z[idx] <= r:
                    z[i] = z[idx]
                else:
                    l = i
                    while r < n and total[r] == total[r - l]:
                        r += 1
                    z[i] = r - l
                    r -= 1

        ans = []
        m = len(pat)
        for i in range(n):
            if z[i] == m:
                ans.append(i - m - 1)
        return ans
