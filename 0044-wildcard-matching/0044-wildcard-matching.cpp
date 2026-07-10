class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1, match = 0;

        while (i < s.length()) {

            // case 1: exact match or '?'
            if (j < p.length() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }

            // case 2: '*' found
            else if (j < p.length() && p[j] == '*') {
                star = j;       // remember position of '*'
                match = i;      // remember match start
                j++;            // move pattern forward
            }

            // case 3: mismatch but we saw a '*'
            else if (star != -1) {
                j = star + 1;   // go after '*'
                match++;        // try to match one more char
                i = match;
            }

            // case 4: mismatch and no '*'
            else {
                return false;
            }
        }

        // remaining pattern should be all '*'
        while (j < p.length() && p[j] == '*') {
            j++;
        }

        return j == p.length();
    }
};