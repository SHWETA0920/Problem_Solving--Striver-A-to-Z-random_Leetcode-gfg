class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> arr(n);
        int maxi = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            arr[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, arr[i]);
            total += arr[i];
        }

        if (k >= total) return 0;

        int left = 0, right = maxi;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long need = 0;

            for (int x : arr) {
                if (x > mid) {
                    need += x - mid;
                }
            }

            if (need <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int level = left;
        long long used = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > level) {
                used += arr[i] - level;
                arr[i] = level;
            }
        }

        long long rem = k - used;

        for (int i = 0; i < n && rem > 0; i++) {
            if (arr[i] == level && level > 0) {
                arr[i]--;
                rem--;
            }
        }

        long long sum = 0;

        for (int x : arr) {
            sum += 1LL * x * x;
        }

        return sum;
    }
};