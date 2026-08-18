class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;

        vector<int> v1(26);
        vector<int> v2(26);

        for (auto x : word1) {
            v1[x - 'a']++;
        }

        for (auto x : word2) {
            v2[x - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((v1[i] == 0 && v2[i] != 0) ||
                (v1[i] != 0 && v2[i] == 0))
                return false;
        }

        unordered_map<int, int> m;

        for (int i = 0; i < 26; i++) {
            if (v1[i] != 0)
                m[v1[i]]++;
        }

        for (int i = 0; i < 26; i++) {
            if (v2[i] != 0) {
                if (m.find(v2[i]) == m.end() || m[v2[i]] == 0)
                    return false;

                m[v2[i]]--;
            }
        }

        return true;
    }
};