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
    vector<int> countBits(int n) {
        vector<int>v;int i;
        for (int j = 0; j < n+1; j++) {
            string ans="";
            int i=j;
            while (i > 0) {
                int rem = i % 2;
                ans += char('0' + rem);
                i = i / 2;
            }
            v.push_back(count(ans));
        }
        return v;
    }
};