class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (auto x : nums1) {
            mp1[x]++;
        }

        for (auto x : nums2) {
            mp2[x]++;
        }

        vector<int> x;

        for (auto it : mp1) {
            if (mp2.find(it.first) == mp2.end()) {
                x.push_back(it.first);
            }
        }

        ans.push_back(x);

        vector<int> y;

        for (auto it : mp2) {
            if (mp1.find(it.first) == mp1.end()) {
                y.push_back(it.first);
            }
        }

        ans.push_back(y);

        return ans;
    }
};