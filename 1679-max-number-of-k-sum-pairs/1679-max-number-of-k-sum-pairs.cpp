class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            int rem = k - nums[i];

            if(mp.find(rem) != mp.end() && mp[rem] > 0) {
                mp[rem]--;
                count++;
            }
            else {
                mp[nums[i]]++;
            }
        }

        return count;
    }
};