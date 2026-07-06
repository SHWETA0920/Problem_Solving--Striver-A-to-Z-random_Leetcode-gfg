class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>t(n,1);
        int maxi=1;
        for (int i = 0; i <n; i++) {
            for (int p = 0; p <i; p++) {
                if(nums[p]<nums[i]){
                    t[i]=max(t[i],t[p]+1);
                    maxi=max(maxi,t[i]);
                }
            }
        }

        return maxi;
    }
};