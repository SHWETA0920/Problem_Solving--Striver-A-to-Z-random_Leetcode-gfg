class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        // Try every divisor k of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            // Process each block of length k
            for (int start = 0; start < n; start += k) {
                unordered_map<int, int> freq;

                // Count the original block's elements
                for (int i = start; i < start + k; i++) {
                    freq[nums[i]]++;
                }

                // Compare its multiset with the matching
                // segment of the globally sorted array
                for (int i = start; i < start + k; i++) {
                    freq[sortedNums[i]]--;
                }

                for (auto& p : freq) {
                    if (p.second != 0) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) break;

                // Check whether this block is a cyclic
                // rotation of a non-decreasing sequence
                int descents = 0;

                for (int i = start; i < start + k; i++) {
                    int next = start + (i - start + 1) % k;

                    if (nums[i] > nums[next]) {
                        descents++;
                    }
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};