class Solution {
public:
    int mutli(int n){
        int res=1;
         while(n>0){
            int rem=n%10;
            res*=rem;
            n=n/10;            
         }
         return res;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int ans=mutli(i);
            if(ans%t==0){
                return i;
            }
        }
        return -1;       
        
    }
};