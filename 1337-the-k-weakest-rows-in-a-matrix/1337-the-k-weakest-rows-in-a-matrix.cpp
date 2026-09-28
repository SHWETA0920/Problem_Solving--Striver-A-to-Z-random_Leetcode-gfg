class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;

        int m = mat.size();
        int n = mat[0].size();

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < m; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    count++;
            }

            pq.push({count, i});

            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};