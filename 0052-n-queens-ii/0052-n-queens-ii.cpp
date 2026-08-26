class Solution {
public:
     
    vector<vector<string>> result;
    int N;
    unordered_set<int>cols;
    unordered_set<int>dia;
    unordered_set<int>antidia;
    void solve(vector<string>& board ,int row){
        if(row>=N){
            result.push_back(board);
            return;
        }
        for(int col=0;col<N;col++){
            int diaC=row+col;
            int antic=row-col;
            if(cols.find(col)!=cols.end() || dia.find(diaC)!=dia.end()|| antidia.find(antic)!=antidia.end()) continue;
            cols.insert(col);
            dia.insert(diaC);
            antidia.insert(antic);

            board[row][col]='Q';

            solve(board,row+1);
            cols.erase(col);
            dia.erase(diaC);
            antidia.erase(antic);
            board[row][col]='.';
        }
            
    }
    int totalNQueens(int n) {
        N=n;
        vector<string> board(n,string(n,'.'));//{"...","...","..."}        
        solve(board,0);
        return result.size();         
    }
};