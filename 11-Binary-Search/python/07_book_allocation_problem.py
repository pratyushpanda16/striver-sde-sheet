class Solution:
    def findPages(self, nums: List[int], m: int) -> int:
        n = len(nums)
        if m > n:
            return -1

        def count_students(max_pages):
            students = 1
            pages_assigned = 0
            for pages in nums:
                if pages_assigned + pages > max_pages:
                    students += 1
                    pages_assigned = pages
                else:
                    pages_assigned += pages
            return students

        low = max(nums)
        high = sum(nums)

        while low <= high:
            mid = (low + high) // 2
            if count_students(mid) <= m:
                high = mid - 1
            else:
                low = mid + 1

        return low
