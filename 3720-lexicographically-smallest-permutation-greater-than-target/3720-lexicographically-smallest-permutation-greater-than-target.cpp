class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        int n = s.size();

        string ans;

        // Try to make prefix equal to target
        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                ans += target[i];
                cnt[x]--;
            }
            else {
                // Cannot match target[i].
                
                // FIRST: try making current position greater
                for (int c = x + 1; c < 26; c++) {

                    if (cnt[c] > 0) {

                        string res = ans;
                        res += char('a' + c);

                        cnt[c]--;

                        // Put remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            res += string(cnt[j], 'a' + j);
                        }

                        return res;
                    }
                }

                // If current position cannot be increased,
                // we need to backtrack.
                for (int j = i - 1; j >= 0; j--) {

                    cnt[ans[j] - 'a']++;

                    int cur = ans[j] - 'a';

                    for (int c = cur + 1; c < 26; c++) {

                        if (cnt[c] > 0) {

                            string res = ans.substr(0, j);
                            res += char('a' + c);

                            cnt[c]--;

                            // Remaining characters smallest possible
                            for (int k = 0; k < 26; k++) {
                                res += string(cnt[k], 'a' + k);
                            }

                            return res;
                        }
                    }
                }

                return "";
            }
        }

        // We matched target exactly.
        // Need STRICTLY greater, so backtrack.
        for (int i = n - 1; i >= 0; i--) {

            cnt[ans[i] - 'a']++;

            int cur = ans[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    string res = ans.substr(0, i);
                    res += char('a' + c);

                    cnt[c]--;

                    for (int j = 0; j < 26; j++) {
                        res += string(cnt[j], 'a' + j);
                    }

                    return res;
                }
            }
        }

        return "";
    }
};