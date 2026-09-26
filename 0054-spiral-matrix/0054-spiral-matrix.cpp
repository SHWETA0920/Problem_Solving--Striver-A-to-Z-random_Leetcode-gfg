class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int minr=0,minc=0,maxr=m-1,maxc=n-1;
        vector<int>ans;
        while(minr<=maxr|| minc<=maxc){
            // right
            for(int i=minc;i<=maxc;i++){
                ans.push_back(mat[minr][i]);
            }
            //down            
            minr++;
            if(minr>maxr || minc>maxc) break; 
            for(int i=minr;i<=maxr;i++){
                ans.push_back(mat[i][maxc]);
            }
            maxc--;
            if(minr>maxr || minc>maxc) break; 
            //left
            for(int i=maxc;i>=minc;i--){
                ans.push_back(mat[maxr][i]);
            }
            maxr--;
            if(minr>maxr || minc>maxc) break; 
            //up
            for(int i=maxr;i>=minr;i--){
                ans.push_back(mat[i][minc]);
            }
            minc++;
        }
        return ans;
    }
};