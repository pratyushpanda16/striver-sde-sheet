class Solution {
public:
    int findPages(vector<int>& nums, int m) {
        int n = nums.size();

        if (m > n) {
            return -1;
        }

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

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

private:
    int countStudents(const vector<int>& nums, int maxPages) {
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
};
