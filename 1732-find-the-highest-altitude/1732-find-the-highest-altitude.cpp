class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int altitude = 0;
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            altitude += gain[i];
            maxi = max(maxi, altitude);
        }

        return maxi;
    }
};