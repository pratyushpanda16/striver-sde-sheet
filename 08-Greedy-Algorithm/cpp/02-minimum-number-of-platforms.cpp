class Solution {
public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure) {
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int n = Arrival.size();
        int platforms = 1, maxPlatforms = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (Arrival[i] <= Departure[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
};
