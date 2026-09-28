class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        // Put first element of every row
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        while (k--) {
            auto x = pq.top();
            pq.pop();

            int value = x.first;
            int row = x.second.first;
            int col = x.second.second;

            if (k == 0)
                return value;

            // Push next element from same row
            if (col + 1 < m) {
                pq.push({matrix[row][col + 1], {row, col + 1}});
            }
        }

        return -1;
    }
};