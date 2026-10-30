class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
                priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();
            if (u == n - 1) {
                return d;
            }
           
           
            if (d > dist[u][count]) {
                continue;
            }
            
            // Traverse all neighbors
            for (const auto& [v, w] : adj[u]) {
                int next_count = (labels[v] == labels[u]) ? (count + 1) : 1;
                
                
                if (next_count <= k) {
                    if (d + w < dist[v][next_count]) {
                        dist[v][next_count] = d + w;
                        pq.push({d + w, v, next_count});
                    }
                }
            }
        }
        
        return -1;
    }
};