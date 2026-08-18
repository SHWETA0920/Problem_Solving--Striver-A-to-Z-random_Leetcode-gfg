class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans;
        unordered_map<int, int> mp;

        for (auto x : nums2) {
            mp[x]++;
        }

        vector<int> x;

        for (int i = 0; i < m; i++) {
            if (mp.find(nums1[i]) == mp.end()) {
                x.push_back(nums1[i]);
            }
        }

        unordered_set<int> st(x.begin(), x.end());
        x.assign(st.begin(), st.end());

        ans.push_back(x);

        vector<int> y;
        unordered_map<int, int> mp2;

        for (auto x : nums1) {
            mp2[x]++;
        }

        for (auto it : mp) {
            if (mp2.find(it.first) == mp2.end()) {
                y.push_back(it.first);
            }
        }

        ans.push_back(y);

        return ans;
    }
};