class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        string ans = "";

        unordered_map<char, int> mp;

        for(char c : s)
            mp[c]++;

        priority_queue<pair<int, char>> pq;

        for(auto it : mp)
            pq.push({it.second, it.first});

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            // Current character is different from previous character
            if(ans.empty() || ans.back() != it.second) {

                ans += it.second;
                it.first--;

                if(it.first > 0)
                    pq.push(it);
            }

            else {
                // Need another character
                if(pq.empty())
                    return "";

                auto b = pq.top();
                pq.pop();

                ans += b.second;
                b.first--;

                if(b.first > 0)
                    pq.push(b);

                // Put the previous character back
                pq.push(it);
            }
        }

        return ans;
    }
};