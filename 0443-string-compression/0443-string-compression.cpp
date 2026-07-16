class Solution {
public:
    int compress(vector<char>& s) {
        int n = s.size();
        int j = 0;
        int i = 0;
               
        while (i < n) {
            char curr = s[i];
            int count = 0;
            while (i<n && s[i] == curr) {
                count++;
                i++;
            } 
            s[j]=curr;
            j++;
            if(count>1){
                string ans=to_string(count);
                for(auto &c:ans){
                    s[j]=c;
                    j++;
                }
            }
        }
        return j;
    }
};