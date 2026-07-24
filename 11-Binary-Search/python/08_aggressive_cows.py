class Solution:
    def aggressiveCows(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)

        low = 1
        high = nums[n - 1] - nums[0]
        ans = 0

        def can_place_cows(min_dist):
            cows_placed = 1
            last_position = nums[0]
            for i in range(1, len(nums)):
                if nums[i] - last_position >= min_dist:
                    cows_placed += 1
                    last_position = nums[i]
                if cows_placed >= k:
                    return True
            return False

        while low <= high:
            mid = (low + high) // 2
            if can_place_cows(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1

        return ans
