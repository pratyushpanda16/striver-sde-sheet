class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = list(map(int, version1.split('.')))
        v2 = list(map(int, version2.split('.')))

        n1, n2 = len(v1), len(v2)
        for i in range(max(n1, n2)):
            a = v1[i] if i < n1 else 0
            b = v2[i] if i < n2 else 0
            if a != b:
                return 1 if a > b else -1

        return 0
