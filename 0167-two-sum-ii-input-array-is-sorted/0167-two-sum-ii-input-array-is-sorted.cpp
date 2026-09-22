class Solution {
public:
    vector<int> twoSum(vector<int>& num, int sum) {
        // since it is sorted , we can do by two pointer concept
        int n=num.size()-1;
        int i=0,j=n;        
        vector<int>ans;
        while(i<j){
            int x=sum-num[i];
            if(num[j]>x) j--;
            else if(num[j]<x) i++;
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
};