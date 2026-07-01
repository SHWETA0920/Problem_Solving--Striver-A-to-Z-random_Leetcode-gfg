class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        int c=0;
        int i=0,j=0;
        while(i<n&& j<n){
            if(s[i]==t[j]){
                c++;
                i++;j++;
            }
            else j++;
        }
        if(c==m) return true;
        return false;        
    }
};