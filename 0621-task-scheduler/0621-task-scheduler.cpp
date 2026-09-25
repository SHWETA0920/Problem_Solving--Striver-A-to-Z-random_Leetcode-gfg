class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for(char c : tasks)
            mp[c]++;
        priority_queue<pair<int,char>> pq;

        for(auto x : mp)
            pq.push({x.second, x.first});
        queue<pair<int,int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()) {
            time++;
            if(!pq.empty()) {
                auto x = pq.top();
                pq.pop();
                int freq = x.first;
                char task = x.second;
                freq--;
                if(freq > 0)
                    q.push({freq, time + n});
            }
            if(!q.empty() && q.front().second == time) {
                pq.push(q.front());
                q.pop();
            }
        }

        return time;
    }
};