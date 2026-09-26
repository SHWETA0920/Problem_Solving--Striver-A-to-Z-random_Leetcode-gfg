class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;

        int n = s.length();
        int i = 0, j = 0;
        int maxi = 0;

        while (j < n) {

            while (j < n && mp[s[j]] < 1) {
                mp[s[j]]++;
                j++;
            }

            maxi = max(maxi, j - i);

            if (j < n) {
                mp[s[i]]--;
                i++;
            }
        }

        return maxi;
    }
};