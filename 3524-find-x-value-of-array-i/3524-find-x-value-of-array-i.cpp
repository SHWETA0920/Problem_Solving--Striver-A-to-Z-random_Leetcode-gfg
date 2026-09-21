class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);

            int x = num % k;

            // Start a new subarray with just nums[i]
            newDp[x]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                int newRemainder = (1LL * r * x) % k;
                newDp[newRemainder] += dp[r];
            }

            // Add all subarrays ending here to answer
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};