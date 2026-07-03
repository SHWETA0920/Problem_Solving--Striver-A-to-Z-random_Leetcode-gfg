class Solution {
public:
    static int t[3][1001];

    int solve(int e, int f) {
        if (f == 0 || f == 1) return f;
        if (e == 1) return f;

        if (t[e][f] != -1) return t[e][f];

        int mini = INT_MAX;

        for (int k = 1; k <= f; k++) {
            int low, high;

            if (t[e-1][k-1] != -1)
                low = t[e-1][k-1];
            else
                low = solve(e-1, k-1);

            if (t[e][f-k] != -1)
                high = t[e][f-k];
            else
                high = solve(e, f-k);

            int temp = 1 + max(low, high);
            mini = min(mini, temp);
        }

        return t[e][f] = mini;
    }

    int twoEggDrop(int n) {
        memset(t, -1, sizeof(t));
        return solve(2, n);
    }
};

// 🔥 REQUIRED definition
int Solution::t[3][1001];