class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m = a.size();
        int n = b.size();

        if (m > n) {
            return kthElement(b, a, k);
        }

        int low = max(0, k - n);
        int high = min(k, m);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n) ? INT_MAX : b[cut2];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return -1;
    }
};
