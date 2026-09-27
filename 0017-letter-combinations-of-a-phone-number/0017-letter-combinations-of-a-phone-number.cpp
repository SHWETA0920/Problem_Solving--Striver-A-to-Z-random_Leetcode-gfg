class Solution {
public:

    void solve(string &digits, int i, string curr,
               vector<string> &ans,
               vector<string> &mp) {

        // We used all digits
        if (i == digits.length()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[i] - '0'];

        for (char ch : letters) {

            curr.push_back(ch);

            solve(digits, i + 1, curr, ans, mp);

            curr.pop_back();   // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> mp = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> ans;

        if (digits.empty())
            return ans;

        solve(digits, 0, "", ans, mp);

        return ans;
    }
};