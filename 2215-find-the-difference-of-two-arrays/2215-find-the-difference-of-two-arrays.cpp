class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        unordered_set<int> s1;
        unordered_set<int> s2;

        for (auto x : nums1) {
            s1.insert(x);
        }

        for (auto y : nums2) {
            s2.insert(y);
        }

        vector<vector<int>> ans(2);

        for (auto x : s1) {
            if (s2.find(x) == s2.end())
                ans[0].push_back(x);
        }

        for (auto x : s2) {
            if (s1.find(x) == s1.end())
                ans[1].push_back(x);
        }

        return ans;
    }
};