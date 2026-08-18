class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> row, col;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                v.push_back(grid[i][j]);
            }
            row.push_back(v);
        }

        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < m; j++) {
                v.push_back(grid[j][i]);
            }
            col.push_back(v);
        }

        map<vector<int>, int> mp;

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