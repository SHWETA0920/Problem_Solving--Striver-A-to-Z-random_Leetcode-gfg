class Solution {
public:
    int expand(string &s, int i, int j) {
        int count = 0;

        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++) {
            // Odd length palindrome
            count += expand(s, i, i);

            // Even length palindrome
            count += expand(s, i, i + 1);
        }

        return count;
    }
};