class Solution {
public:
    void res(string &s, int lo, int hi){
        while(lo < hi){
            swap(s[lo], s[hi]);
            lo++; hi--;
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        string temp = "";
        int i = 0;

        while(i < n){
            while(i < n && s[i] == ' ') i++; 
            if(i >= n) break;
            if(!temp.empty()) temp += ' ';
            while(i < n && s[i] != ' '){
                temp += s[i];
                i++;
            }
        }
        s = temp;
        reverse(s.begin(), s.end());
        n = s.size();
        int left = 0;
        i = 0;

        while(i < n){
            while(i < n && s[i] != ' ') i++;
            int right = i - 1;
            res(s, left, right);

            left = i + 1;
            i++;
        }

        return s;
    }
};