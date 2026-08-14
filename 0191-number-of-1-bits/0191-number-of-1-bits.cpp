class Solution {
public:
    int count(string s) {
        int i = 0, count = 0;
        while (i < s.length()) {
            if (s[i] == '1') count++;
            i++;
        }
        return count;
    }
    int hammingWeight(int i) {
        string ans="";
       while (i > 0) {
                int rem = i % 2;
                ans += char('0' + rem);
                i = i / 2;
            }
        return count(ans);     
        
    }
};