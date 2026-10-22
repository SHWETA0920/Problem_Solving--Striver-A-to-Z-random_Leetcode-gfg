class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Find the index of the element 0
        int zero = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }
        
        bool is_increasing = true;
        bool is_decreasing = true;
        
        // Check both cyclic trends relative to the position of '0'
        for (int i = 0; i < n; ++i) {
            // Increasing index check: (zero + nums[i]) % n must land back on i
            if (nums[(zero + nums[i]) % n] != nums[i]) {
                is_increasing = false;
            }
            // Decreasing index check: (zero - nums[i] + n) % n must land back on i
            if (nums[(zero - nums[i] + n) % n] != nums[i]) {
                is_decreasing = false;
            }
        }
        
        int ans = INT_MAX;
        if (is_increasing) {
            ans = min(ans, zero);          
            ans = min(ans, n - zero + 2);  
        }
        
        // Scenario 2: The array forms a decreasing cyclic sequence
        if (is_decreasing) {
            ans = min(ans, n - zero);      // Pure path using rotations/reversals
            ans = min(ans, zero + 2);      // Mirror mixed path
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};