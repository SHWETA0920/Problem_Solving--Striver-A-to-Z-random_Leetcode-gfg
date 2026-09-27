class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        int i = 0;

        stack<char> st;
        deque<char> dq;

        while (i < n) {

            if (s[i] == ')') {

                // Take elements until '('
                while (!st.empty() && st.top() != '(') {
                    dq.push_back(st.top());
                    st.pop();
                }

                // Remove '('
                st.pop();

                // Put reversed part back into stack
                while (!dq.empty()) {
                    st.push(dq.front());
                    dq.pop_front();
                }
            }
            else {
                st.push(s[i]);
            }

            i++;
        }

        string ans = "";

        while (!st.empty()) {
            dq.push_front(st.top());
            st.pop();
        }

        while (!dq.empty()) {
            ans += dq.front();
            dq.pop_front();
        }

        return ans;
    }
};