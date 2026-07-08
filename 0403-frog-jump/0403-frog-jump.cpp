class Solution {
public:
int n;
unordered_map<int,int>mp;
int t[2001][2001];
int solve(vector<int>& stones,int curr,int prev){
    if(curr==n-1) return true;
    if(t[curr][prev]!=-1) return t[curr][prev];
    bool result=false;
    for(int i=prev-1;i<=prev+1;i++){
        if(i>0){
            int next=stones[curr]+i;
            if(mp.find(next)!=mp.end()){
                result=result || solve(stones,mp[next],i);
            }
        }
    }
    return t[curr][prev]= result;
}
    
    bool canCross(vector<int>& stones) {
        n =stones.size();
        memset(t,-1,sizeof(t));
        if(stones[1]!=1) return false;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return solve(stones,0,0);
    }
};