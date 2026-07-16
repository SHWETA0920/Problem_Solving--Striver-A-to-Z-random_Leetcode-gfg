class Solution {
public:
    string convert(string a){
        int n = a.length();
        int i = 0;
        string ans = "";
        
        while(i < n){
            char curr = a[i];
            int count = 0;            
           
            while(i < n && a[i] == curr){
                count++;
                i++;
            }
            
            ans += to_string(count);
            ans += curr;
        }
        return ans;
    }

    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string ip = "1";        
        
        for(int i = 2; i <= n; i++){
            ip = convert(ip);
        }
        
        return ip;
    }
};