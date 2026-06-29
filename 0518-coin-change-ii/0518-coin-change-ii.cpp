class Solution {
public:
    int  isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(sum+1, 0)); 
        const int MOD = 1e9 + 7;
      
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){                
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i][j-arr[i-1]] + dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int change(int amount, vector<int>& coins) {
        return isSubsetSum(coins,amount);
        
    }
};