class Solution {
public:
    int ans = -1;

    void dfs(int node, int depth, vector<int>& edges,
             vector<int>& visited, vector<int>& curr, vector<int>& prev) {

        visited[node] = 1;
        curr[node] = 1;
        prev[node] = depth;

        int next = edges[node];

        if (next != -1) {
            
            if (!visited[next]) {
                dfs(next, depth + 1, edges, visited, curr, prev);
            }

            else if (curr[next] == 1) {
                int cyclelen = depth - prev[next] + 1;
                ans = max(ans, cyclelen);
            }
        }

        // backtrack
        curr[node] = 0;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> visited(n, 0);
        vector<int> curr(n, 0);
        vector<int> prev(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, 0, edges, visited, curr, prev);
            }
        }

        return ans;
    }
};