class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++) {

            int freq[26] = {0};

            for (int j = i; j < n; j++) {

                // Add current character
                freq[s[j] - 'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                // Find max and min frequency
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                sum += maxi - mini;
            }
        }

        return sum;
    }
};