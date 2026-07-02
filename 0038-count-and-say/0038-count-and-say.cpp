class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        for(int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;
            
            for(int j = 1; j < res.size(); j++) {
                if(res[j] == res[j - 1]) {
                    count++;
                } else {
                    temp += to_string(count) + res[j - 1];
                    count = 1;
                }
            }
            
            // last group
            temp += to_string(count) + res.back();
            res = temp;
        }
        
        return res;
    }
};