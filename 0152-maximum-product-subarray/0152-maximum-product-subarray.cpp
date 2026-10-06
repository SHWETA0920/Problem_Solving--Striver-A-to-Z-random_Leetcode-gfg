class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int res = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
           int v1=nums[i];
           int v2=minProd*nums[i];
           int v3=maxProd*nums[i];
           maxProd=max(v1,max(v2,v3));
           minProd=min(v1,min(v2,v3));
           res=max(res,max(maxProd,minProd));
        }

        return res;
    }
};