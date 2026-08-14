class Solution {
public:
    string binary(int nums){
        int i=nums;
        string ans="";
        while (i > 0) {
                int rem = i % 2;
                ans += char('0' + rem);
                i = i / 2;
            }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string convertDateToBinary(string date) {
        string ans="";
        string y="";
        int i=0;
        while(i<date.length()+1){
            if(date[i]=='-'){                
                int p=stoi(y);
                ans+=binary(p);
                ans+="-";
                y="";
            }
            else if(i==date.length()){                
                int p=stoi(y);
                ans+=binary(p);              
            }
            else y+=date[i];
            i++;
        }
        return ans;       
        
    }
};