class Solution { 
public: 
    bool pali(string s) { 
        int n = s.length(); 
        int i = 0, j = n - 1; 
        
        while(i <= j) { 
            if(s[i] != s[j]) return false; 
            
            i++;
            j--;
        } 
        
        return true; 
    } 
    
    int countSubstrings(string s) { 
        int n = s.length(); 
        int count = 0; 
        
        for(int i = 0; i < n; i++) { 
            for(int j = i; j < n; j++) { 
                
                string a = s.substr(i, j - i + 1); 
                
                if(pali(a)) 
                    count++; 
            } 
        } 
        
        return count; 
    } 
};