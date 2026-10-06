class Solution { 
public:
    int minisum(vector<int>& nums) {
        int n = nums.size(); 
        int best = nums[0]; 
        int res = nums[0];      
 
        for (int idx = 1; idx < n; idx++) {  
            int v1 = best + nums[idx]; 
            int v2 = nums[idx]; 
 
            best = min(v1, v2); 
            res = min(res, best); 
        } 
 
        return res; 
    } 

    int maxSubarraySumCircular(vector<int>& nums) { 
        int n = nums.size(); 
 
        int best = nums[0]; 
        int res = nums[0]; 
        int sum = 0;

        for (int i = 0; i < n; i++) 
            sum += nums[i];

        int x = minisum(nums);
 
        for (int i = 1; i < n; i++) { 
 
            int v1 = best + nums[i]; 
            int v2 = nums[i]; 
 
            best = max(v1, v2); 
            res = max(res, best); 
        } 
        if (res < 0)
            return res;

        int ans = max(res, sum - x);
 
        return ans; 
    } 
};