class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(numCourses);

        // Build graph
        for (auto& p : pre) {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course); // prereq → course
        }

        // Indegree
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (auto nbr : adj[i]) {
                indegree[nbr]++;
            }
        }
       
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
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

        if (ans.size() != numCourses) return {};

        return ans;
    }
};