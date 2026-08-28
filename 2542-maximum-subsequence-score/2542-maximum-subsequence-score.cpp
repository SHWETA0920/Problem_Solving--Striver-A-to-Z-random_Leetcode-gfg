class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (int i = 0; i < m; i++) {
            pq.push({nums2[i], nums1[i]});
        }

        vector<int> p; // nums2
        vector<int> q; // nums1

        while (!pq.empty()) {
            p.push_back(pq.top().first);
            q.push_back(pq.top().second);
            pq.pop();
        }

        long long ans = 0;  // FIXED
        long long sum = 0;

        priority_queue<int, vector<int>, greater<int>> temp;

        for (int i = n - 1; i >= 0; i--) {

            temp.push(q[i]);
            sum += q[i];

            if (temp.size() > k) {
                sum -= temp.top();
                temp.pop();
            }

            if (temp.size() == k) {
                ans = max(ans, sum * p[i]);
            }
        }

        return ans;
    }
};