class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long countAmounts(long long x, vector<int>& coins) {

        int n = coins.size();
        long long ans = 0;

        // Try every subset of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long long commonMultiple = 1;
            int bits = 0;
            bool tooLarge = false;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    commonMultiple =
                        lcm(commonMultiple, coins[i]);

                    if (commonMultiple > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge)
                continue;

            long long current = x / commonMultiple;

            if (bits % 2 == 1) {
                ans += current;
            }
            else {
                ans -= current;
            }
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;

        long long minCoin =
            *min_element(coins.begin(), coins.end());

        long long high = minCoin * 1LL * k;

        while (low < high) {

            long long mid =
                low + (high - low) / 2;

            long long cnt = countAmounts(mid, coins);

            if (cnt >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};