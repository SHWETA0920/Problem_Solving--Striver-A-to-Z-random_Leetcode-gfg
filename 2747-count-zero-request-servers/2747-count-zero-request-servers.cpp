class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
       
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // Sort logs by time: logs[i][1] is the timestamp
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Map to keep track of active server request frequencies within the window
        unordered_map<int, int> serverCount;
        
        int left = 0;  // Left pointer of the sliding window
        int right = 0; // Right pointer of the sliding window
        
        for (int i = 0; i < m; ++i) {
            int qTime = sortedQueries[i].first;
            int qIndex = sortedQueries[i].second;
            
            int rangeStart = qTime - x;
            int rangeEnd = qTime;
           
            while (right < logs.size() && logs[right][1] <= rangeEnd) {
                serverCount[logs[right][0]]++;
                right++;
            }
            while (left < logs.size() && logs[left][1] < rangeStart) {
                int serverId = logs[left][0];
                serverCount[serverId]--;
                if (serverCount[serverId] == 0) {
                    serverCount.erase(serverId);
                }
                left++;
            }
            ans[qIndex] = n - serverCount.size();
        }
        
        return ans;
    }
};