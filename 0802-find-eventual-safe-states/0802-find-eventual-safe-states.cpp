class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& curr)
    {
        visited[node] = 1;
        curr[node] = 1;

        for(int nbr : adj[node])
        {
            if(!visited[nbr]) {
                if(dfs(nbr, adj, visited, curr) == false)
                    return false; 
            }
            else {
                if(curr[nbr] == 1) {
                    return false; 
                }
            }
        }

        curr[node] = 0; 
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> visited(n, 0);
        vector<int> curr(n, 0);

        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            if(dfs(i, graph, visited, curr))
                ans.push_back(i);
        }

        return ans;
    }
};