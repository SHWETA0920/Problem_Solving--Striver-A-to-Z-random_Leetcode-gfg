class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(n);

        for (auto& p : pre) {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course); // edge: prereq → course
        }
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto nbr : adj[i]) {
                indegree[nbr]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        if(ans.size()!=n) return false;
        return true;
        
    }
};