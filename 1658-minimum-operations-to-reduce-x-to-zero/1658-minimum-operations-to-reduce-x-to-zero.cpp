class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;

        // Calculate the total sum
        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        // If target is negative, impossible
        if (target < 0) {
            return -1;
        }

        int left = 0;
        int sum = 0;
        int maxLength = -1;

        // Sliding window
        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Shrink the window if sum exceeds target
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            // Check if the current window has the target sum
            if (sum == target) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        // If no valid subarray exists
        if (maxLength == -1) {
            return -1;
        }

        return n - maxLength;
    }
};