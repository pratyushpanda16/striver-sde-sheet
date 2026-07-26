class Solution {
    ArrayList<Integer> search(String pat, String txt) {
        String total = pat + "$" + txt;
        int n = total.length();
        int[] z = new int[n];
        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i > r) {
                l = r = i;
                while (r < n && total.charAt(r) == total.charAt(r - l))
                    r++;
                z[i] = r - l;
                r--;
            } else {
                int idx = i - l;
                if (i + z[idx] <= r) {
                    z[i] = z[idx];
                } else {
                    l = i;
                    while (r < n && total.charAt(r) == total.charAt(r - l))
                        r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        int m = pat.length();
        for (int i = 0; i < n; i++) {
            if (z[i] == m) {
                ans.add(i - m - 1);
            }
        }
        return ans;
    }
}
