class Solution {
    public int findPages(int[] nums, int m) {
        int n = nums.length;

        if (m > n) {
            return -1;
        }

        int low = Arrays.stream(nums).max().getAsInt();
        int high = Arrays.stream(nums).sum();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countStudents(nums, mid) <= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    private int countStudents(int[] nums, int maxPages) {
        int students = 1;
        int pagesAssigned = 0;

        for (int pages : nums) {
            if (pagesAssigned + pages > maxPages) {
                students++;
                pagesAssigned = pages;
            } else {
                pagesAssigned += pages;
            }
        }

        return students;
    }
}
