class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n= cards.size();
        int lsum=0,rsum=0, ans=0;
        for(int i=0;i<k;i++) lsum+=cards[i];
        ans=lsum;
        int ridx=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cards[i];
            rsum+=cards[ridx];
            ridx=ridx-1;
            ans=max(ans,lsum+rsum);
           
        }
        return ans;
        
    }
};
