class Solution {
public:
    vector<string> result;
    void solve( string curr,int n,int open ,int close ){
        if(close==n){
            result.push_back(curr);
            return;
        }
        if(open<n) solve(curr+'(',n,open+1,close);
        if(close<open) solve(curr+')',n,open,close+1);

    }
    vector<string> generateParenthesis(int n) {
        string curr="";int open=0,close=0;
        solve(curr,n ,open ,close);
        return result;
        
    }
};