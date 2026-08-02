class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        // Convert 2D board → 1D array (with zig-zag order)
        vector<int> arr(n*n + 1, -1);
        int idx = 1;
        bool leftToRight = true;
        
        for(int i = n - 1; i >= 0; i--) {
            if(leftToRight) {
                for(int j = 0; j < n; j++) {
                    arr[idx++] = board[i][j];
                }
            } else {
                for(int j = n - 1; j >= 0; j--) {
                    arr[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }
        
        // BFS
        queue<pair<int,int>> q; // {cell, moves}
        vector<bool> vis(n*n + 1, false);
        
        q.push({1, 0});
        vis[1] = true;
        
        while(!q.empty()) {
            auto [cell, moves] = q.front();
            q.pop();
            
            if(cell == n*n) return moves;
            
            for(int dice = 1; dice <= 6; dice++) {
                int next = cell + dice;
                if(next > n*n) break;
                
                if(arr[next] != -1) {
                    next = arr[next]; // snake or ladder
                }
                
                if(!vis[next]) {
                    vis[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        
        return -1;
    }
};