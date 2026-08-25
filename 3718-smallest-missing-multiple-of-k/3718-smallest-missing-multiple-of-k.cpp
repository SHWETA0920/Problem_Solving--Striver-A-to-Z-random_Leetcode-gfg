class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int x=200/k;
        for(int i=1;i<=x;i++){
            int a=k*i;
            if(mp.find(a)==mp.end()){
                return a;                
            }
        }
        return 0;
        
    }
};