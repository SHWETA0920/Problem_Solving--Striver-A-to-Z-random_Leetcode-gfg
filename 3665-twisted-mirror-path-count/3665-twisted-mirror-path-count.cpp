class Solution {
public:
    long long MOD = 1e9 + 7;
    int m, n;
    long long memo[505][505][2];
    bool visited[505][505][2];

    // Helper to simulate reflection and return the final landed (row, col, dir) or (-1, -1, -1) if invalid
    // dir: 0 -> moving right, 1 -> moving down
    pair<pair<int, int>, int> reflect(int r, int c, int dir, const vector<vector<int>>& grid) {
        while (true) {
            int nr = r + (dir == 1 ? 1 : 0);
            int nc = c + (dir == 0 ? 1 : 0);

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                return {{-1, -1}, -1}; // out of bounds
            }

            if (grid[nr][nc] == 0) {
                return {{nr, nc}, dir}; // lands on empty cell, keeps current dir
            } else {
                // Hits a mirror at (nr, nc)
                r = nr;
                c = nc;
                // If it entered while moving right (dir == 0), it turns down (dir = 1)
                // If it entered while moving down (dir == 1), it turns right (dir = 0)
                dir = 1 - dir;
            }
        }
    }

    long long solve(int r, int c, int dir, const vector<vector<int>>& grid) {
        if (r == m - 1 && c == n - 1) return 1;
        if (visited[r][c][dir]) return memo[r][c][dir];

        long long ways = 0;

        // Try moving right (dir = 0) and down (dir = 1)
        for (int nextDir = 0; nextDir < 2; ++nextDir) {
            auto nextState = reflect(r, c, nextDir, grid);
            int nr = nextState.first.first;
            int nc = nextState.first.second;
            int nd = nextState.second;

            if (nr != -1) {
                ways = (ways + solve(nr, nc, nd, grid)) % MOD;
            }
        }

        visited[r][c][dir] = true;
        return memo[r][c][dir] = ways;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(visited, 0, sizeof(visited));
        
        // Start from (0, 0)
        // From (0, 0), we can initially choose to move right or down
        long long totalPaths = 0;
        for (int initialDir = 0; initialDir < 2; ++initialDir) {
            auto nextState = reflect(0, 0, initialDir, grid);
            int nr = nextState.first.first;
            int nc = nextState.first.second;
            int nd = nextState.second;
            if (nr != -1) {
                totalPaths = (totalPaths + solve(nr, nc, nd, grid)) % MOD;
            }
        }
        return totalPaths;
    }
};