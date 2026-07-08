class Solution {
public:
    
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;  // dp[i-2]
        int prev1 = 0;  // dp[i-1]

        for (int i = start; i <= end; i++) {
            int take = nums[i] + prev2;
            int skip = prev1;

            int curr = max(take, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case
        if (n == 1) return nums[0];

        // Case 1: exclude last house
        int case1 = robLinear(nums, 0, n - 2);

        // Case 2: exclude first house
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};