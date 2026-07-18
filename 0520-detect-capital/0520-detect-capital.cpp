class Solution {
public:
   bool check( string s, char start,char end){
    for(char c:s){
        if(c<start || c>end) return false;
    }
    return true;
   }
    bool detectCapitalUse(string s) {
        if(check(s,'a','b') || check(s,'A','Z') || check(s.substr(1),'a','z')) return true;
        return false;
        
    }
};