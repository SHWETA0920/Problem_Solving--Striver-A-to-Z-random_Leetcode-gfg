class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        
        vector<int> first(26, n), last(26, -1);      
        for(int i = 0; i < n; i++){
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }
        
        vector<pair<int,int>> intervals;        
        
        for(int i = 0; i < n; i++){
            if(i != first[s[i] - 'a']) continue;
            
            int end = last[s[i] - 'a'];
            bool valid = true;
            
            for(int j = i; j <= end; j++){
                if(first[s[j] - 'a'] < i){
                    valid = false;
                    break;
                }
                end = max(end, last[s[j] - 'a']);
            }
            
            if(valid){
                intervals.push_back({i, end});
            }
        }
        
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        
        vector<string> result;
        int prevEnd = -1;
        
        for(auto &it : intervals){
            if(it.first > prevEnd){
                result.push_back(s.substr(it.first, it.second - it.first + 1));
                prevEnd = it.second;
            }
        }
        
        return result;
    }
};