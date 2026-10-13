
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        unordered_map<string, int> mp;
        int i = 0, j = 0;

        while (j < s.size()) {
            string ans = "";
            int start = j;

            while (j < s.size() && s[j] != ' ') j++;

            ans = s.substr(start, j - start);
            j++;

            mp[ans]++;
            i++;
        }

        if (i != n) return false;

        unordered_map<char, int> mp1;
        for (char c : pattern) mp1[c]++;

        if (mp.size() != mp1.size()) return false;

        unordered_map<char, string> mp2;
        unordered_map<string, char> mp3;

        i = 0;
        j = 0;

        while (j < s.size()) {
            int start = j;
            while (j < s.size() && s[j] != ' ') j++;

            string ans = s.substr(start, j - start);
            char c = pattern[i];

            if (mp2.count(c) && mp2[c] != ans) return false;
            if (mp3.count(ans) && mp3[ans] != c) return false;

            mp2[c] = ans;
            mp3[ans] = c;

            i++;
            j++;
        }

        return true;
    }
};
