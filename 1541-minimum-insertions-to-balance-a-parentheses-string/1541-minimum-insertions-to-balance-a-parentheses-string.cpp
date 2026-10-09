class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.length();
        int i = 0;
        int count = 0;

        while (i < n) {
            if (s[i] == '(') {
                st.push('(');
            }
            else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;  // consume the second ')'
                }
                else {
                    count++; // insert a missing ')'
                }

                if (!st.empty()) {
                    st.pop();
                }
                else {
                    count++; // insert a missing '('
                }
            }
            i++;
        }

        count += 2 * st.size(); // each remaining '(' needs two ')'

        return count;
    }
};