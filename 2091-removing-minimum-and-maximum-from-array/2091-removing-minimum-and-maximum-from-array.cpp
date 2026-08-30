
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;

            if (nums[i] > nums[mx])
                mx = i;
        }

        int left = min(mn, mx);
        int right = max(mn, mx);

        // 3 possibilities:
        // 1. Remove both from left
        int removeLeft = right + 1;

        // 2. Remove both from right
        int removeRight = n - left;

        // 3. Remove one from each side
        int removeBoth = (left + 1) + (n - right);

        return min({removeLeft, removeRight, removeBoth});
    }
};
