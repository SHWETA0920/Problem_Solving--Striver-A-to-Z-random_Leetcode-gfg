class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        if (mini == maxi)
            return 0;

        int minCount = 0;
        int maxCount = 0;

        for (int x : nums) {
            if (x == mini)
                minCount++;

            if (x == maxi)
                maxCount++;
        }

        return n - minCount - maxCount;
    }
};