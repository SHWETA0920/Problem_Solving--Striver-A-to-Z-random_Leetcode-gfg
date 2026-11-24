class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        long long max_lcm = 1;
        int max_val = 1;
        for (int x : nums) {
            max_lcm = lcm(max_lcm, static_cast<long long>(x));
            max_val = max(max_val, x);
        }
        // Any valid subarray has prod == lcm * gcd <= max_lcm * max_val
        long long max_prod = max_lcm * max_val;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                if (prod > max_prod / x) {
                    break;
                }
                prod *= x;
                g = (j == i) ? x : gcd(g, x);
                l = lcm(l, x);

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};