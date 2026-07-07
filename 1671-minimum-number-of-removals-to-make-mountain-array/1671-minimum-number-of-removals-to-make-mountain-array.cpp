class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, 1);   // LIS
        vector<int> t1(n, 1);  // LDS

        // LIS
        for (int i = 0; i < n; i++) {
            for (int p = 0; p < i; p++) {
                if (nums[p] < nums[i]) {
                    t[i] = max(t[i], t[p] + 1);
                }
            }
        }

        // LDS
        for (int i = n - 1; i >= 0; i--) {
            for (int p = n - 1; p > i; p--) {
                if (nums[p] < nums[i]) {
                    t1[i] = max(t1[i], t1[p] + 1);
                }
            }
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (t[i] > 1 && t1[i] > 1) {   
                maxi = max(maxi, t[i] + t1[i] - 1);
            }
        }

        return n - maxi;
    }
};