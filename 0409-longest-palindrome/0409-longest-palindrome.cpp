class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        int count = 0;
        bool odd = false;

        for (auto it : mp) {
            int y = it.second;

            if (y % 2 == 0) {
                count += y;
            }
            else {
                count += y - 1;
                odd = true;
            }
        }

        if (odd)
            count++;

        return count;
    }
};