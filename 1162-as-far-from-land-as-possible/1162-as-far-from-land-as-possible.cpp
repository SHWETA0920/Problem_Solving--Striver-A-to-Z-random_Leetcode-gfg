class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int,int>> q;
        
        // Push all land cells
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        
        // Edge case
        if(q.empty() || q.size() == n*n) return -1;
        
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int dist = -1;
        
        // BFS
        while(!q.empty()){
            int size = q.size();
            dist++;
            
            while(size--){
                auto p = q.front(); q.pop();
                int r = p.first;
                int c = p.second;
                
                for(auto &d : dir){
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                        grid[nr][nc] = 1; // mark visited
                        q.push({nr,nc});
                    }
                }
            }
        }
        
        return dist;
    }
};