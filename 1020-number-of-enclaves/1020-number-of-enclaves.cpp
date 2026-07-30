class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1) return;

        grid[i][j]=2;

        for(int k=0;k<4;k++){
            int ii=i+dx[k], jj=j+dy[k];
            dfs(grid,ii,jj,n,m);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        //  remove boundary-connected land
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) dfs(grid,i,0,n,m);
            if(grid[i][m-1]==1) dfs(grid,i,m-1,n,m);
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1) dfs(grid,0,j,n,m);
            if(grid[n-1][j]==1) dfs(grid,n-1,j,n,m);
        }

        //  count remaining land
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};