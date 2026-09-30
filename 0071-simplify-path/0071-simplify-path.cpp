class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();

        for (int i = 0; i < n; ) {

            // Skip '/'
            if (path[i] == '/') {
                i++;
                continue;
            }

            // Get one directory name
            string s = "";

            while (i < n && path[i] != '/') {
                s += path[i];
                i++;
            }

            // Current directory
            if (s == ".") {
                continue;
            }

            // Parent directory
            else if (s == "..") {
                if (!st.empty())
                    st.pop();
            }

            // Normal directory
            else {
                st.push(s);
            }
        }

        // Build answer
        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};