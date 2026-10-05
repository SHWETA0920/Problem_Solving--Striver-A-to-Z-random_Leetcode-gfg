class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0;
        int count = 0;

        for (char c : s) {
            if (c == 'b') {
                b++;
            }
            else { // c == 'a'
                count = min(count + 1, b);
            }
        }

        return count;
    }
};