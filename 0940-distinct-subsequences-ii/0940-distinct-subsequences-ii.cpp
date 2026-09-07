class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;        
        vector<long long> last(26, 0);

        for (char ch : s) {
            int c = ch - 'a';

            long long total = 1; 
            for (int i = 0; i < 26; i++) {
                total = (total + last[i]) % MOD;
            }

            last[c] = total;
        }

        long long ans = 0;

        for (long long x : last) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};