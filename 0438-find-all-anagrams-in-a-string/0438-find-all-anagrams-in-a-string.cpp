class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freqW(26,0);
        vector<int>freqP(26,0);
        for(char x:p){
            freqP[x-'a']++;
        }
        int l=0;int m=p.size();
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            freqW[s[i]-'a']++;
            if(i-l+1==m){
                if(freqW==freqP) ans.push_back(l);
                freqW[s[l]-'a']--;
                l++;
            }
        }
        return ans;        
    }
};