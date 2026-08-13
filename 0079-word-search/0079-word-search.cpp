class Solution {
public:

    bool dfs(vector<vector<char>>& grid, int r, int c,
             string& word, int index) {

        int n = grid.size();
        int m = grid[0].size();

        // Out of bounds
        if(r < 0 || r >= n || c < 0 || c >= m)
            return false;

        // Current character doesn't match
        if(grid[r][c] != word[index])
            return false;

        // We found the complete word
        if(index == word.size() - 1)
            return true;

        // Mark visited
        char temp = grid[r][c];
        grid[r][c] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if(dfs(grid, nr, nc, word, index + 1))
                return true;
        }

        // Backtrack
        grid[r][c] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& grid, string word) {

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == word[0]) {

                    if(dfs(grid, i, j, word, 0))
                        return true;
                }
            }
        }

        return false;
    }
};