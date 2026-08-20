class Solution {
public:
    vector<pair<int, int>> sort_rf(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> ans;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (int i = 0; i < start.size(); i++) {
            pq.push({start[i], end[i]});
        }

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }

    int maxEvents(vector<vector<int>>& events) {
        int x = events.size();

        vector<int> start(x);
        vector<int> end(x);

        for (int i = 0; i < x; i++) {
            start[i] = events[i][0];
            end[i] = events[i][1];
        }

        vector<pair<int, int>> ans = sort_rf(start, end);

        priority_queue<int, vector<int>, greater<int>> pq;

        int count = 0;
        int i = 0;
        int day = 1;

        while (i < x || !pq.empty()) {

            if (pq.empty())
                day = max(day, ans[i].first);

            // Add events which have started
            while (i < x && ans[i].first <= day) {
                pq.push(ans[i].second);
                i++;
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            if (!pq.empty()) {
                pq.pop();
                count++;
                day++;
            }
        }

        return count;
    }
};