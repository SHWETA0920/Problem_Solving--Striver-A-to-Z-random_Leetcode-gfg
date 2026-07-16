class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n=v1.size();
        int m=v2.size();
        int i=0,j=0;
        while(i<n || j<m){
            int n1=0,n2=0;
            while(i<n && v1[i]!='.'){
                n1=n1*10+(v1[i]-'0');
                i++;                
            }
            while(j<m && v2[j]!='.'){
                n2=n2*10+(v2[j]-'0');
                j++;                
            }
            if(n1>n2) return 1;
            if(n1<n2) return -1;
            i++;
            j++;
            
        }
        return 0;       
        
    }
};