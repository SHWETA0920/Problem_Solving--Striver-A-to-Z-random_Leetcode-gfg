class Solution {
public:
    bool checkString(string s) {
        bool seenB = false;

        for (char c : s) {
            if (c == 'b') {
                seenB = true;
            }
            
            if (seenB && c == 'a') {
                return false;
            }
        }

        return true;
    }
};