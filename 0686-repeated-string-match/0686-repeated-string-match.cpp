class Solution {
public:
    bool isSubstring(string& a, string& b, int n, int m){   
        for(int i = 0; i <= n - m; i++){   
            int j = 0;
            while(j < m && a[i + j] == b[j]){
                j++;
            }
            if(j == m) return true;  
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        string s = a;
        int c = 1;
        while(s.size() <= m + 2*n){
            if(isSubstring(s, b, s.length(), m)) return c;
            s.append(a);
            c++;
        }
        return -1;
    }
};