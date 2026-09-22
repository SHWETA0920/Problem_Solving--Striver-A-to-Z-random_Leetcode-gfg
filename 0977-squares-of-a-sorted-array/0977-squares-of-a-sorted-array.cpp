class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        for(int i=0;i<n;i++){
            arr[i]=arr[i]*arr[i];
        }
        sort(arr.begin(),arr.end());
        return arr;        
    }
};