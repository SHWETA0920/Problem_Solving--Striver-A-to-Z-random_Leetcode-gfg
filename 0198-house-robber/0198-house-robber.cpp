class Solution {
public:
    int t[101];

    int solve(vector<int>& nums, int n) {
        t[0] = 0;
        t[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + t[i - 2];
            int skip = t[i - 1];

            t[i] = max(steal, skip);
        }

        return t[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        return solve(nums, n);
    }
};