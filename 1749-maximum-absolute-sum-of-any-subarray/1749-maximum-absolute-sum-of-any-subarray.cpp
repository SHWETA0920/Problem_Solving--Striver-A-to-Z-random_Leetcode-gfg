class Solution {
public:
    int maxsum(vector<int>& nums) {
        int best = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int v1 = best + nums[i];
            int v2 = nums[i];

            best = max(v1, v2);
            res = max(res, best);
        }

        return res;
    }

    int minsum(vector<int>& nums) {
        int best = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int v1 = best + nums[i];
            int v2 = nums[i];

            best = min(v1, v2);
            res = min(res, best);
        }

        return res;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int a = maxsum(nums);
        int b = minsum(nums);

        return max(abs(a), abs(b));
    }
};