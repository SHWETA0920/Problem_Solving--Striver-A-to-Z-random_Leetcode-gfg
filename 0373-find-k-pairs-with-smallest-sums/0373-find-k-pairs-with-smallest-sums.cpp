class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {

        vector<vector<int>> ans;

        // {sum, i, j}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        int m = nums1.size();
        int n = nums2.size();

        // Put the first pair of each row
        for (int i = 0; i < min(m, k); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (k > 0 && !pq.empty()) {

            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});
            k--;

            // Move to the next element in the same row
            if (j + 1 < n) {
                pq.push({
                    nums1[i] + nums2[j + 1],
                    i,
                    j + 1
                });
            }
        }

        return ans;
    }
};