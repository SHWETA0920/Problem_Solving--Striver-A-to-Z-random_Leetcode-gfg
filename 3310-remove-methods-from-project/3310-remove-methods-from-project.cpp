class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        // Step 1: Build graph
        vector<vector<int>> adj(n);
        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Step 2: Find reachable from k
        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int node) {
            vis[node] = true;
            for (int nei : adj[node]) {
                if (!vis[nei]) dfs(nei);
            }
        };
        dfs(k);

        // Step 3: Check if any outside node points inside
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!vis[u] && vis[v]) {
                // invalid case → return all nodes
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            }
        }

        // Step 4: Otherwise return nodes not reachable
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) res.push_back(i);
        }

        return res;
    }
};