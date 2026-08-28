class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;
        vector<int> cnt(26, 0);
        for(char c : s) cnt[c - 'a']++;
        
        // Validate palindrome capability
        int odd = 0;
        char mid = 0;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }
        if(odd > 1) return "";
        
        // Count pool for the left half
        vector<int> half(26, 0);
        for(int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }
        
        // Helper to construct full palindrome from a completed left half
        auto build_palindrome = [&](const string& left) {
            string full = left;
            if (n % 2 != 0) full += mid;
            for (int j = m - 1; j >= 0; j--) {
                full += left[j];
            }
            return full;
        };

        string left_half = "";
        int match_len = 0;
        
        // Phase 1: Try matching target's prefix exactly as far as possible
        for (int i = 0; i < m; i++) {
            int t_char = target[i] - 'a';
            if (half[t_char] > 0) {
                half[t_char]--;
                left_half += target[i];
                match_len++;
            } else {
                break;
            }
        }

        // Case A: We fully matched the first half of target
        if (match_len == m) {
            string candidate = build_palindrome(left_half);
            if (candidate > target) {
                return candidate;
            }
        }

        // Case B: Try placing a larger available character right at the first mismatch spot
        if (match_len < m) {
            int t_char = target[match_len] - 'a';
            for (int c = t_char + 1; c < 26; c++) {
                if (half[c] > 0) {
                    half[c]--;
                    left_half += char('a' + c);
                    
                    // Fill remaining spots greedily with the smallest available
                    for (int k = 0; k < 26; k++) {
                        while (half[k] > 0) {
                            left_half += char('a' + k);
                            half[k]--;
                        }
                    }
                    return build_palindrome(left_half);
                }
            }
        }

        // Case C: If the first mismatch spot can't be upgraded (or full match wasn't > target),
        // we backtrack from right to left across the matched prefix.
        for (int i = match_len - 1; i >= 0; i--) {
            int current_char = left_half[i] - 'a';
            half[current_char]++;
            left_half.pop_back();

            int t_char = target[i] - 'a';
            // Find the smallest character GREATER than target[i]
            for (int c = t_char + 1; c < 26; c++) {
                if (half[c] > 0) {
                    half[c]--;
                    left_half += char('a' + c);
                    
                    // Fill remaining suffix of left_half with smallest available characters
                    for (int k = 0; k < 26; k++) {
                        while (half[k] > 0) {
                            left_half += char('a' + k);
                            half[k]--;
                        }
                    }
                    return build_palindrome(left_half);
                }
            }
        }

        return "";
    }
};
