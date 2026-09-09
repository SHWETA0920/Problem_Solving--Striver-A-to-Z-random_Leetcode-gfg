class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long p = 1000; p <= n; ) {
            // Every number from p to n has at least one
            // additional comma.
            ans += n - p + 1;

            // Prevent overflow while calculating p * 1000
            if (p > n / 1000)
                break;

            p *= 1000;
        }

        return ans;
    }
};