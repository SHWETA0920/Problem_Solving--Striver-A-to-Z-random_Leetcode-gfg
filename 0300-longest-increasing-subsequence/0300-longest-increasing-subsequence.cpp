class Solution {
public:
    int t[2501][2501];
    int solve(vector<int>& nums,int i,int p){
        int n=nums.size();
        if(i>=n) return 0;
        if(p!=-1 && t[i][p]!=-1) return t[i][p];
        int take=0,skip=0;
        if(p==-1 || nums[p]<nums[i]) take=1+solve(nums,i+1,i);
        skip=solve(nums,i+1,p);
        if(p!=-1) t[i][p]=max(take,skip);
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,-1);
        
    }
};