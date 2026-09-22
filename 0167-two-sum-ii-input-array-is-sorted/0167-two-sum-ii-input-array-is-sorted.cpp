class Solution {
public:
    vector<int> twoSum(vector<int>& num, int sum) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=num.size();
        for(int i=0;i<n;i++){
            mp[num[i]]=i;
        }
        for(int i=0;i<n;i++){
            int x=sum-num[i];
            if(mp.find(x)!=mp.end()){
                ans.push_back(i+1);
                ans.push_back(mp[x]+1);
                break;
            }
        }
        return ans;      
    }
};