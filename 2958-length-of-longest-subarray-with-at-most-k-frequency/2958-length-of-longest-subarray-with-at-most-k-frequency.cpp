class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            
            // Add nums[right] to the window
            mp[nums[right]]++;

            // If frequency becomes greater than k,
            // shrink the window from left
            while (mp[nums[right]] > k) {
                mp[nums[left]]--;
                left++;
            }

            // Current window is good
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};