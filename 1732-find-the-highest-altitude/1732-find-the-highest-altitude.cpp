class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        vector<int> pref(n + 1);

        pref[0] = 0;
        int maxi = pref[0];

        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + gain[i - 1];
            maxi = max(maxi, pref[i]);
        }

        

        return maxi;
    }
};