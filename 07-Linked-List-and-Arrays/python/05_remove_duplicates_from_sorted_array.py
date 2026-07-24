class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        insert_pos = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[insert_pos - 1]:
                nums[insert_pos] = nums[i]
                insert_pos += 1

        return insert_pos
