class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        int maxi = 0;

        st.push(-1);

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                }
                else {
                    int count = i - st.top();
                    maxi = max(maxi, count);
                }
            }
        }

        return maxi;
    }
};