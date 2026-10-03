class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        
        int maxi = *max_element(nums.begin(), nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        if(mini==maxi) return 0;
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        
        int ans=n-mp[mini]-mp[maxi];
        return ans;        
    }
};