class Solution {
public:
    int lcs1(string a, string b){
    int m = a.size(), n = b.size();
    vector<vector<int>> t(m+1, vector<int>(n+1, 0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return m-t[m][n];
}
    int minInsertions(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        return lcs1(s,r);
        
    }
};