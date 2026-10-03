class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.length();
        int m = goal.length();

        if (n != m) return false;

        unordered_map<char, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }

        if (mp.find(goal[0]) == mp.end())
            return false;

        // Try every possible position of goal[0]
        for (int start : mp[goal[0]]) {

            int x = start;
            bool possible = true;

            for (int j = 1; j < m; j++) {

                int expected = (x + j) % n;

                if (s[expected] != goal[j]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                return true;
        }

        return false;
    }
};