class Solution {
public:
    vector<vector<int>> adj, up;
    vector<int> tin, tout, bit;
    int timer = 0, LOG;

    // Standard BIT point update
    void add(int i, int val, int n) {
        for (; i <= n; i += i & -i) {
            bit[i] ^= val;
        }
    }

    // Range update using two point updates in the BIT
    void update_subtree(int l, int r, int val, int n) {
        add(l, val, n);
        add(r + 1, val, n);
    }

    // Point query to get root-to-node path XOR mask
    int get(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) {
            res ^= bit[i];
        }
        return res;
    }

    void dfs(int u, int p, int n, string &s) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        // Initially add the character to the entire subtree of u
        update_subtree(tin[u], tin[u], 1 << (s[u] - 'a'), n); 

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, n, s);
        }

        tout[u] = timer;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int j = LOG - 1; j >= 0; j--) {
            if (!isAncestor(up[u][j], v)) {
                u = up[u][j];
            }
        }
        return up[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n, vector<int>(LOG, 0));
        // Fenwick tree size needs to accommodate up to tout[u] + 1
        bit.assign(n + 2, 0); 

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Run initial DFS
        dfs(0, 0, n, s);

        // A second pass fixes the prefix paths dynamically for initial configuration
        // Since we did point additions in DFS, we transform them into subtree ranges now
        vector<int> initial_masks(n + 2, 0);
        for (int i = 0; i < n; i++) {
            int val = 1 << (s[i] - 'a');
            initial_masks[tin[i]] ^= val;
            initial_masks[tout[i] + 1] ^= val;
        }
        
        // Re-initialize bit with correct range-encoded modifications
        bit.assign(n + 2, 0);
        for (int i = 1; i <= n + 1; i++) {
            if (initial_masks[i] != 0) {
                add(i, initial_masks[i], n + 1);
            }
        }

        vector<bool> ans;

        for (const string &q : queries) {
            // Fast parsing without stringstream overhead
            if (q[0] == 'u') { // "update ui c"
                int u = 0;
                int i = 7;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                char c = q[i + 1];

                int change = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                // Update the subtree of u across the Euler tour array
                update_subtree(tin[u], tout[u], change, n + 1);
                s[u] = c;
            } else { // "query ui vi"
                int u = 0, v = 0;
                int i = 6;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                i++;
                while (i < q.size()) {
                    v = v * 10 + (q[i] - '0');
                    i++;
                }

                int w = lca(u, v);

                int maskU = get(tin[u]);
                int maskV = get(tin[v]);
                int maskW = 1 << (s[w] - 'a');

                int pathMask = maskU ^ maskV ^ maskW;

                // A bitmask forms a palindrome if it has at most 1 bit set
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};