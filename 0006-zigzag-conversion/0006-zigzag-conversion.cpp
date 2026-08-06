class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> rows(numRows);
        int i = 0, step = 1;

        for(int j = 0; j < s.size(); j++) {
            rows[i] += s[j];

            if(i == 0) step = 1;
            else if(i == numRows - 1) step = -1;

            i += step;
        }

        string ans = "";
        for(int k = 0; k < numRows; k++) {
            ans += rows[k];
        }

        return ans;
    }
};