class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> dp;
        int max_len = 0;
        
        for (int x : nums) {
            // 1. Option: Increment x to x + 1 (must be evaluated first)
            dp[x + 1] = dp[x] + 1;
            
            // 2. Option: Keep x as x
            dp[x] = dp[x - 1] + 1;
            
            // Track the global maximum length found so far
            max_len = max({max_len, dp[x], dp[x + 1]});
        }
        
        return max_len;
    }
};