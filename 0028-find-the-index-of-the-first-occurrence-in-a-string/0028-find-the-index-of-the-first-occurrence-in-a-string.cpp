class Solution {
public:
    vector<int> buildZ(string s) {
        int n = s.size();
        vector<int> z(n, 0);

        int l = 0, r = 0;

        for(int i = 1; i < n; i++){
            if(i <= r)
                z[i] = min(r - i + 1, z[i - l]);

            while(i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;

            if(i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;

        string combined = needle + "$" + haystack;
        vector<int> z = buildZ(combined);

        int m = needle.size();

        for(int i = 0; i < z.size(); i++){
            if(z[i] == m){
                return i - m - 1; 
            }
        }
        return -1;
    }
};