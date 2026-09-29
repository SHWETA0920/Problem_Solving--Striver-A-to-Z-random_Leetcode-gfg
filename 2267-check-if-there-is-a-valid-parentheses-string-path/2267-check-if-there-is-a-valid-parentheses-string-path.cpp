class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {

        // Balance can never become negative
        if (balance < 0)
            return false;

        // Too much balance to possibly close
        if (balance > (m - i) + (n - j) - 1)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        // Move down
        if (i + 1 < m) {
            int newBalance = balance;

            if (grid[i + 1][j] == '(')
                newBalance++;
            else
                newBalance--;

            ans = ans || solve(grid, i + 1, j, newBalance);
        }

        // Move right
        if (j + 1 < n) {
            int newBalance = balance;

            if (grid[i][j + 1] == '(')
                newBalance++;
            else
                newBalance--;

            ans = ans || solve(grid, i, j + 1, newBalance);
        }

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 == 1)
            return false;

        // First character must be '('
        if (grid[0][0] == ')')
            return false;

        int maxBalance = m + n;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(maxBalance, -1)
            )
        );

        return solve(grid, 0, 0, 1);
    }
};