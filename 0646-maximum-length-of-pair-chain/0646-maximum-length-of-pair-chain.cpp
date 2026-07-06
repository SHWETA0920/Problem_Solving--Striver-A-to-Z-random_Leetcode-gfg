class Solution {
public:
    int findLongestChain(vector<vector<int>>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        vector<int>t(n,1);
        int maxi=1;
        for (int i = 0; i <n; i++) {
            for (int p = 0; p <i; p++) {
                if(nums[p][1]<nums[i][0]){
                    t[i]=max(t[i],t[p]+1);
                    maxi=max(maxi,t[i]);
                }
            }
        }

        return maxi;
        
    }
};