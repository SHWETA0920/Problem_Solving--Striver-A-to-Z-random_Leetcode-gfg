class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0;
        int ans = 0;

        vector<int> freq(26, 0);

        for (int r = 0; r < n; r++) {
            freq[s[r] - 'a']++;

            // If any character occurs more than 2 times,
            // shrink the window from the left
            while (freq[s[r] - 'a'] > 2) {
                freq[s[l] - 'a']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};