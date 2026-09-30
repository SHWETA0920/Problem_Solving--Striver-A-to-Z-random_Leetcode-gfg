class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char,int>> st;
        string ans="";     
        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;

                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({c, 1});          
            }
        }
        while(!st.empty()){
            while(st.top().second--)ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};