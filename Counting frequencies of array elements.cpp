class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int &it:arr){
            mp[it]++;
        }
         for(int i=1;i<=n;i++){
             int a=i-1;
             if(mp.find(i)!=mp.end()) arr[a]=mp[i];
             else arr[a]=0;
         }
         return arr;
    
    
    }
};
