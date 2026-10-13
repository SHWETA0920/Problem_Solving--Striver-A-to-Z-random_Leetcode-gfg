
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        unordered_map<char, string> mp;
        unordered_map<string, char> mp1;

        int i = 0, j = 0;

        while (j < s.size()) {
            string ans = "";

            while (j < s.size() && s[j] != ' ') {
                ans += s[j];
                j++;
            }

            char c = pattern[i];

            if (mp.count(c) && mp[c] != ans)
                return false;

            if (mp1.count(ans) && mp1[ans] != c)
                return false;

            mp[c] = ans;
            mp1[ans] = c;

            i++;
            j++;
        }

        return i == n;
    }
};
