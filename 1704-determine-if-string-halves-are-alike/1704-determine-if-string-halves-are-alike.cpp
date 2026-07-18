class Solution {
public:
    int count(string s){
        int n=s.length();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ) c++;
        }
        return c;
    }
    bool halvesAreAlike(string s) {
        int n=s.length();        
        string first=s.substr(0,n/2);
        string second=s.substr(n/2);
        return count(first)==count(second);       
        
    }
};