class Solution {
    public int[] maxSumCombinations(int[] nums1, int[] nums2, int k) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int n = nums1.length;
        int[] result = new int[k];

        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
            (a, b) -> b[0] - a[0]
        );

        Set<String> visited = new HashSet<>();

        int i = n - 1, j = n - 1;
        maxHeap.offer(new int[]{nums1[i] + nums2[j], i, j});
        visited.add(i + "," + j);

        for (int idx = 0; idx < k; idx++) {
            int[] top = maxHeap.poll();
            result[idx] = top[0];
            int r = top[1], c = top[2];

            if (r - 1 >= 0 && !visited.contains((r - 1) + "," + c)) {
                maxHeap.offer(new int[]{nums1[r - 1] + nums2[c], r - 1, c});
                visited.add((r - 1) + "," + c);
            }

            if (c - 1 >= 0 && !visited.contains(r + "," + (c - 1))) {
                maxHeap.offer(new int[]{nums1[r] + nums2[c - 1], r, c - 1});
                visited.add(r + "," + (c - 1));
            }
        }

        return result;
    }
}
