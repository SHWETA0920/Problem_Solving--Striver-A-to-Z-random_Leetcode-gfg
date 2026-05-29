class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int groupSize) {
        int n=nums.size();
        if(n%groupSize!=0) return false;

        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        while(!m.empty()){            
            int t= m.begin()->first;         
            for(int i=0;i<groupSize;i++){
                int ans=t+i;
                if(m.find(ans)==m.end()) return false; 
                else{
                    m[ans]--;
                    if(m[ans]==0) m.erase(ans);
                }              
            }            
        }
        return true;        
    }
};
