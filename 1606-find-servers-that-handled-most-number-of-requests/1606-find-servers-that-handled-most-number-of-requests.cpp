class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Min-heap stores pairs: {free_time, server_id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        
        // Set of currently available server IDs
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        vector<int> requestsCount(k, 0);
        
        for (int i = 0; i < arrival.size(); ++i) {
            long long currTime = arrival[i];
            long long duration = load[i];
            
            // Free up servers whose work finishes at or before currTime
            while (!busy.empty() && busy.top().first <= currTime) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            // If all servers are busy, drop the request
            if (available.empty()) {
                continue;
            }
            
            // Find the first available server >= (i % k)
            int target = i % k;
            auto it = available.lower_bound(target);
            
            // If no server >= target, wrap around to the first available server in the set
            if (it == available.end()) {
                it = available.begin();
            }
            
            int serverId = *it;
            available.erase(it);
            busy.push({currTime + duration, serverId});
            requestsCount[serverId]++;
        }
        
        // Find the maximum number of requests handled by any server
        int maxRequests = *max_element(requestsCount.begin(), requestsCount.end());
        vector<int> busiest;
        for (int i = 0; i < k; ++i) {
            if (requestsCount[i] == maxRequests) {
                busiest.push_back(i);
            }
        }
        
        return busiest;
    }
};