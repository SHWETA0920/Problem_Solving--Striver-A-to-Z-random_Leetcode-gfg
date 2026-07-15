class Solution {
public:
   int remove(string &s,string target,int score){
    string temp="";
    int ans=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(!temp.empty() && temp.back()==target[0] && s[i]==target[1]){
            temp.pop_back();
            ans+=score;
        }
        else{
            temp.push_back(s[i]);
        }
    }
    s=temp;
    return ans;
   }

    int maximumGain(string s, int x, int y) {
        int total =0;
        if(x>y){
            total+=remove(s,"ab",x);
            total+=remove(s,"ba",y);
        }
        else{
            total+=remove(s,"ba",y);
            total+=remove(s,"ab",x);
        }
        return total;
        
    }
};