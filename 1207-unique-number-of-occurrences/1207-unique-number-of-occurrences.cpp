class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;
        unordered_map<int, int> rev;

        for (auto x : arr) {
            mp[x]++;
        }

        for (auto it : mp) {
            if (rev.find(it.second) != rev.end())
                return false;
            rev[it.second] = it.first;
        }

        return true;
    }
};