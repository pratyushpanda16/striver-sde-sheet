class Solution:
    def findPlatform(self, Arrival: List[int], Departure: List[int]) -> int:
        Arrival.sort()
        Departure.sort()

        n = len(Arrival)
        platforms, max_platforms = 1, 1
        i, j = 1, 0

        while i < n and j < n:
            if Arrival[i] <= Departure[j]:
                platforms += 1
                i += 1
            else:
                platforms -= 1
                j += 1
            max_platforms = max(max_platforms, platforms)

        return max_platforms
