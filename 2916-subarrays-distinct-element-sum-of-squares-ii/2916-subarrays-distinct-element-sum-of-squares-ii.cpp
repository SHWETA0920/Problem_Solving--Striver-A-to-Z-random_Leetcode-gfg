class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> sum(4 * n), sq(4 * n), lazy(4 * n);

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr) -> void {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                sq[node] = (sq[node] + 2 * lazy[node] * sum[node]
                           + (r - l + 1LL) * lazy[node] * lazy[node]) % MOD;
                sum[node] = (sum[node] + (r - l + 1LL) * lazy[node]) % MOD;
                lazy[node] = 0;
                return;
            }

            int mid = (l + r) / 2;
            self(self, node * 2, l, mid, ql, qr);
            self(self, node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        // A simpler O(n log n) solution can use a segment tree
        // with lazy range addition and sum-of-squares maintenance.
        auto add = [&](auto&& self, int node, int l, int r,
                       int ql, int qr, long long val) -> void {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                sq[node] = (sq[node] + 2 * val * sum[node]
                           + (r - l + 1LL) * val * val) % MOD;
                sum[node] = (sum[node] + (r - l + 1LL) * val) % MOD;
                lazy[node] = (lazy[node] + val) % MOD;
                return;
            }

            int mid = (l + r) / 2;

            // Push pending lazy updates to children.
            if (lazy[node]) {
                long long v = lazy[node];
                for (int child = node * 2; child <= node * 2 + 1; child++) {
                    int a = (child == node * 2 ? l : mid + 1);
                    int b = (child == node * 2 ? mid : r);
                    long long len = b - a + 1LL;
                    sq[child] = (sq[child] + 2 * v * sum[child] + len * v * v) % MOD;
                    sum[child] = (sum[child] + len * v) % MOD;
                    lazy[child] = (lazy[child] + v) % MOD;
                }
                lazy[node] = 0;
            }

            self(self, node * 2, l, mid, ql, qr, val);
            self(self, node * 2 + 1, mid + 1, r, ql, qr, val);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        long long ans = 0;
        unordered_map<int, int> last;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            // For every subarray ending at i, distinct count increases
            // by one exactly when its starting index is in [prev+1, i].
            add(add, 1, 0, n - 1, prev + 1, i, 1);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};