class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(auto a:nums){
            mp[a]++;
        }
        int small=nums[0];
        int large=nums[n-1];


        
        vector<int>ans;
        int x=small;
        for(int i=small ;i<=large;i++){                     
           if(mp.find(i)==mp.end()) ans.push_back(i);
           
        }
        return ans;
        
    }
};