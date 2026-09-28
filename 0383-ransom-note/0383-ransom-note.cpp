class Solution {
public:
    bool canConstruct(string ran, string mag) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        int n=ran.size();
        int m=mag.size();
        if(m<n) return false;
        for(char c:ran) m1[c]++;
        for(char d:mag) m2[d]++;
        for(auto it:m1){
            int x=it.first;
            if(it.second>m2[x]) return false;
        }        
        return true;
    }
};