class Solution {
public:
    unordered_map<string, bool> mp;

    bool solve(const string& a, const string& b) {
        if (a == b) return true;
        if (a.length() != b.length()) return false;

        string key = a + "#" + b;
        if (mp.find(key) != mp.end()) return mp[key];

        int n = a.length();

        // 🔥 pruning (important)
        string temp1 = a, temp2 = b;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if (temp1 != temp2) {
            return mp[key] = false;
        }

        for (int i = 1; i < n; i++) {

            // Case 1: swapped
            if (solve(a.substr(0, i), b.substr(n - i, i)) &&
                solve(a.substr(i), b.substr(0, n - i))) {
                return mp[key] = true;
            }

            // Case 2: not swapped
            if (solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i), b.substr(i))) {
                return mp[key] = true;
            }
        }

        return mp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};