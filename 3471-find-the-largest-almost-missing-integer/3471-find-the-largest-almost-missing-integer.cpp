class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> freq;
        
        // Count how many windows of size k contain each number
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen;
            
            for (int j = i; j < i + k; j++) {
                if (!seen.count(nums[j])) {
                    freq[nums[j]]++;
                    seen.insert(nums[j]);
                }
            }
        }
        
        int ans = -1;
        
        // Largest number appearing in exactly one window
        for (auto &[num, count] : freq) {
            if (count == 1) {
                ans = max(ans, num);
            }
        }
        
        return ans;
    }
};