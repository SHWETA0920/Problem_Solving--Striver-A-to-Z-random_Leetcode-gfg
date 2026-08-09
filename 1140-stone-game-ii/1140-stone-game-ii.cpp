class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int i, int M, vector<int>& piles) {
        if (i >= n) return 0;

        // If we can take all remaining piles
        if (2 * M >= n - i) {
            return suffix[i];
        }

        if (dp[i][M] != -1) return dp[i][M];

        int ans = INT_MAX;

        for (int X = 1; X <= 2 * M; X++) {
            int next = solve(i + X, max(M, X), piles);
            ans = min(ans, next);  // opponent minimizes
        }

        return dp[i][M] = suffix[i] - ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.assign(n, vector<int>(n + 1, -1));
        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        return solve(0, 1, piles);
    }
};