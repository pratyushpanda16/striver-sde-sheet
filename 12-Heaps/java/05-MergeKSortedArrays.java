class Solution {
    public List<Integer> mergeKSortedArrays(int[][] arr, int k) {
        List<Integer> result = new ArrayList<>();

        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );

        for (int i = 0; i < k; i++) {
            minHeap.offer(new int[]{arr[i][0], i, 0});
        }

        while (!minHeap.isEmpty()) {
            int[] top = minHeap.poll();
            int val = top[0], row = top[1], col = top[2];

            result.add(val);

            if (col + 1 < arr[row].length) {
                minHeap.offer(new int[]{arr[row][col + 1], row, col + 1});
            }
        }

        return result;
    }
}
