class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(i + 1) == mp.end()) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};