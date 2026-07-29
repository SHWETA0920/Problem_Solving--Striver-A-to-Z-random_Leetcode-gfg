class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // build graph
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // dp[node][color]
        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;

        // push nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int visited = 0;
        int ans = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            // update answer
            for (int c = 0; c < 26; c++) {
                ans = max(ans, dp[node][c]);
            }

            for (int nbr : adj[node]) {

                // transfer dp values
                for (int c = 0; c < 26; c++) {
                    dp[nbr][c] = max(dp[nbr][c], dp[node][c]);
                }

                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    dp[nbr][colors[nbr] - 'a']++;
                    q.push(nbr);
                }
            }
        }

        // cycle check
        if (visited != n) return -1;

        return ans;
    }
};