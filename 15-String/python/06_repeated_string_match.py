class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        set_a = set(a)
        for c in b:
            if c not in set_a:
                return -1

        min_reps = (len(b) + len(a) - 1) // len(a)
        repeated = a * min_reps

        if b in repeated:
            return min_reps

        if b in repeated + a:
            return min_reps + 1

        return -1
