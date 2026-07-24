class Solution {
    public int findPlatform(int[] Arrival, int[] Departure) {
        Arrays.sort(Arrival);
        Arrays.sort(Departure);

        int n = Arrival.length;

        int platforms = 1;
        int maxPlatforms = 1;

        int i = 1;
        int j = 0;

        while (i < n && j < n) {
            if (Arrival[i] <= Departure[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }

            maxPlatforms = Math.max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
}
