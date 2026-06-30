class Solution {
public:
    string lcs1(string a, string b){
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

    int i = m, j = n;
    string ans = "";

    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--; j--;
        }
        else if(t[i-1][j] > t[i][j-1]){
            ans += a[i-1];
            i--;
        }
        else{
            ans += b[j-1];
            j--;
        }
    }
    while(i>0){
        ans += a[i-1];
        i--;
    }
    while(j>0){
        ans += b[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
    string shortestCommonSupersequence(string str1, string str2) {
        return lcs1(str1,str2);
        
    }
};