class Solution {
public:

    void dfs(int node, vector<vector<int>>& grid, vector<int>& vis)
    {
        vis[node]=1;

        int n=grid.size();

        for(int j=0;j<n;j++)
        {
            if(grid[node][j]==1 && !vis[j])
            {
                dfs(j,grid,vis);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<int> vis(n,0);

        int cnt=0;


        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,grid,vis);
            }
        }


        return cnt;
    }
};