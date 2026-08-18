class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<string> row, col;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            string s = "";

            for (int j = 0; j < n; j++) {
                s += to_string(grid[i][j]) + "#";
            }

            row.push_back(s);
        }

        for (int i = 0; i < n; i++) {
            string s = "";

            for (int j = 0; j < m; j++) {
                s += to_string(grid[j][i]) + "#";
            }

            col.push_back(s);
        }

        unordered_map<string, int> mp;

        for (auto x : row) {
            mp[x]++;
        }

        int count = 0;

        for (auto x : col) {
            if (mp.find(x) != mp.end()) {
                count += mp[x];
            }
        }

        return count;
    }
};