class Solution {
public:
    int solve(vector<int>& a, int k, int n, int i, int idx) {

        if(a.size() == 1) return a[0];

        idx = (i + k - 1) % a.size();

        a.erase(a.begin() + idx);

        return solve(a, k, n, idx, idx);
    }

    int findTheWinner(int n, int k) {
        vector<int> ans(n);

        for(int i = 1; i <= n; i++)
            ans[i-1] = i;

        int idx = k - 1;

        return solve(ans, k, n, 0, idx);
    }
};