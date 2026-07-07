class Solution {
public:
   bool check(int i,int j){
    if(i% j==0 ||j %i ==0) return true ;
    return false;
   }
      
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>t(n,1);
        vector<int>prev(n,-1);
              int last=0;
              int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(nums[j],nums[i])){
                    if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        prev[i]=j;
                    }
                    if(t[i]>maxi){
                        maxi=t[i];
                        last=i;
                    }
                }

            }
        }
        vector<int>res;
        while(last!=-1){
            res.push_back(nums[last]);
            last=prev[last];
            

        }
        return res;
        
    }
};