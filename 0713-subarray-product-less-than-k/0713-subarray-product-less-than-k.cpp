class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,prod=1;
        int count=0;
        while(i<n){ 
            prod=1;           
            while(j<n && prod<k){
                prod*=nums[j];
                if(prod<k) count++;
                j++;
            }
            prod=prod/nums[i];
            i++;
            j=i;
        }
        return count;        
    }
};