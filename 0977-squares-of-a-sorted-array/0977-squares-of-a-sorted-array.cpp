class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        int i = 0;
        int j = n - 1;
        int k = n - 1;

        while (i <= j) {
            if (abs(arr[i]) > abs(arr[j])) {
                ans[k] = arr[i] * arr[i];
                i++;
            }
            else {
                ans[k] = arr[j] * arr[j];
                j--;
            }
            k--;
        }

        return ans;
    }
};