class Solution {
public:
    bool dfs(int node, int destination, unordered_map<int, vector<int>> &adj, vector<bool> &visited) {
        if (node == destination) return true;

        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination, adj, visited))
                    return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(n, false);

        return dfs(source, destination, adj, visited);
    }
};