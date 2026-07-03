class Solution {
public:
    int t[101][10001];

    int solve(int e, int f) {
        if (f == 0 || f == 1) return f;
        if (e == 1) return f;

        if (t[e][f] != -1) return t[e][f];

        int low = 1, high = f;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            int left, right;

            if (t[e-1][mid-1] != -1)
                left = t[e-1][mid-1];
            else
                left = solve(e-1, mid-1);

            if (t[e][f-mid] != -1)
                right = t[e][f-mid];
            else
                right = solve(e, f-mid);

            int temp = 1 + max(left, right);

            if (left < right) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

            ans = min(ans, temp);
        }

        return t[e][f] = ans;
    }

    int superEggDrop(int k, int n) {
        memset(t, -1, sizeof(t));
        return solve(k, n);  
    }
};