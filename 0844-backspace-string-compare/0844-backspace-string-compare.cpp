class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>s1;
        stack<int>s2;
        
        string a="",b="";
        for(char c:s){
            if(c=='#' && !s1.empty()) s1.pop();
           // if( s1.empty() && c=='#' ) continue;
            else if(isalpha(c)) s1.push(c);
        }
        for(char c:t){
            if(c=='#' &&!s2.empty()) s2.pop();
           // if(s2.empty() && c=='#') continue;
            else if(isalpha(c)) s2.push(c);
        }
        while(!s1.empty()){
            a+=s1.top();
            s1.pop();
        }
        while(!s2.empty()){
            b+=s2.top();
            s2.pop();
        }
        return a==b;        
    }
};