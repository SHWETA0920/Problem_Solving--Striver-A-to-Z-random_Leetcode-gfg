class Solution {
public:
    int slidingWindow(vector<int>& nums,int k){
        unordered_map<int,int>m;
        int n=nums.size();
        int l=0,r=0,count=0;
        while(r<n){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums,k)-slidingWindow(nums,k-1);
        
    }
};
