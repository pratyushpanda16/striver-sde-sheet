class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        from collections import Counter
        freq = Counter(candidates)
        pairs = sorted(freq.items())
        result = []

        def backtrack(index, remaining, current):
            if remaining == 0:
                result.append(list(current))
                return
            if index == len(pairs):
                return

            val, count = pairs[index]
            for copies in range(count + 1):
                if val * copies > remaining:
                    break
                current.extend([val] * copies)
                backtrack(index + 1, remaining - val * copies, current)
                for _ in range(copies):
                    current.pop()

        backtrack(0, target, [])
        return result
