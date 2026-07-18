class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<int>f1(26);
        vector<int>f2(26);
        for(int i=0;i<n;i++){
            f1[word1[i]-'a']++;
        }
        for(int i=0;i<m;i++){
            f2[word2[i]-'a']++;
        }
        for(int i=0;i<=25;i++){
            if(f1[i]!=0 && f2[i]==0) return false;
            if(f1[i]==0 && f2[i]!=0) return false;

        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        for(int i=0;i<=25;i++){
            if(f1[i]!=f2[i] ) return false;
        }
        return true;        
    }
};