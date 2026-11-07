class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
       
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busy_servers;
        
        // Initially, all servers are free
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }
        
        vector<int> ans(m);
        long long t = 0; // Current simulation time
        
        for (int i = 0; i < m; ++i) {
            
            t = max(t, (long long)i);
            
            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= t) {
                auto [free_time, weight, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight, idx});
            }
           
            if (free_servers.empty()) {
                t = get<0>(busy_servers.top());
                while (!busy_servers.empty() && get<0>(busy_servers.top()) == t) {
                    auto [free_time, weight, idx] = busy_servers.top();
                    busy_servers.pop();
                    free_servers.push({weight, idx});
                }
            }
            
            // 3. Assign the task to the top free server
            auto [weight, idx] = free_servers.top();
            free_servers.pop();
            
            ans[i] = idx;
           busy_servers.push({t + tasks[i], weight, idx});
        }
        
        return ans;
    }
};
