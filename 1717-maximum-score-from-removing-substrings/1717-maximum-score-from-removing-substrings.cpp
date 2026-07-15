class Solution {
public:
    int removePair(string &s, string target, int val) {
        string temp;
        int score = 0;

        for (char c : s) {
            if (!temp.empty() && temp.back() == target[0] && c == target[1]) {
                temp.pop_back();
                score += val;
            } else {
                temp.push_back(c);
            }
        }

        s = temp; // update string after removal
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
            total += removePair(s, "ab", x);
            total += removePair(s, "ba", y);
        } else {
            total += removePair(s, "ba", y);
            total += removePair(s, "ab", x);
        }

        return total;
    }
};