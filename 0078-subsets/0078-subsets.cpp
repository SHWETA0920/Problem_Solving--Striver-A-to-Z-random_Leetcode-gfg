class Solution {
public:
    void solve(vector<int>v,vector<int>& nums,vector<vector<int>>&a,int idx,int n){
        if(idx==n){
            a.push_back(v);
            return ;
        }          
        solve(v,nums,a,idx+1,n);
        v.push_back(nums[idx]);
        solve(v,nums,a,idx+1,n);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>a;
        int n=nums.size();
        solve(v,nums,a,0,n);
        return a;        
    }
};