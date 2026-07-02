class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // palindrome table
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 2 || isPal[i+1][j-1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // 1D dp
        vector<int> dp(n, 0);

        for(int i = 0; i < n; i++) {
            if(isPal[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = INT_MAX;
                for(int j = 0; j < i; j++) {
                    if(isPal[j+1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n-1];
    }
};