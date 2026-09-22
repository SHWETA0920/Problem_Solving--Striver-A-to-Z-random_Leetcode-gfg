class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        if(n==1) return 1;
        while(i<n && j<n){
            while(j<n && nums[i]==nums[j]){
                j++;                
            }            
            i++;
            if(j<n) nums[i]=nums[j];
            
        }
        return i;
        
    }
};