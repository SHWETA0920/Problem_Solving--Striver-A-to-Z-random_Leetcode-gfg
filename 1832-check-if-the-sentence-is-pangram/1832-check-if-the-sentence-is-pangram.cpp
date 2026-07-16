class Solution {
public:
    bool checkIfPangram(string sen) {
        int n=sen.length();
        set<char>s;

        for(int i=0;i<n;i++){
            s.insert((int)sen[i]);
        }
        for(int i=97 ;i<=122;i++){
            if(s.find(i)==s.end()) return false;
        }
        return true;
        
    }
};