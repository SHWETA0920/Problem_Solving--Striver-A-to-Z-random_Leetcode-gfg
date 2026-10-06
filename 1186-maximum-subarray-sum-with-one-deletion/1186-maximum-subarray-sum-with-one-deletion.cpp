class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = arr[0];

        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int newNoDelete = max(arr[i],
                                  noDelete + arr[i]);

            int newOneDelete = max(noDelete,
                                   oneDelete + arr[i]);

            noDelete = newNoDelete;
            oneDelete = newOneDelete;

            ans = max(ans, max(noDelete, oneDelete));
        }

        return ans;
    }
};