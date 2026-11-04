class Solution {
public:
    int m;
    vector<int> bit_cnt;
    vector<long long> bit_sum;

    // Add an element to the Fenwick tree
    void add(int idx, int val) {
        for (int i = idx; i <= m; i += i & -i) {
            bit_cnt[i] += 1;
            bit_sum[i] += val;
        }
    }

    // Remove an element from the Fenwick tree
    void remove(int idx, int val) {
        for (int i = idx; i <= m; i += i & -i) {
            bit_cnt[i] -= 1;
            bit_sum[i] -= val;
        }
    }

    // Query prefix count and prefix sum up to idx
    pair<int, long long> query(int idx) {
        int cnt = 0;
        long long sum = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            cnt += bit_cnt[i];
            sum += bit_sum[i];
        }
        return {cnt, sum};
    }

    // Binary lifting on Fenwick tree to find the compressed index of the k-th element
    int find_kth(int k_th) {
        int idx = 0;
        int current_sum = 0;
        int p = 1;
        while (p <= m) p <<= 1;
        p >>= 1;
        while (p > 0) {
            if (idx + p <= m && current_sum + bit_cnt[idx + p] < k_th) {
                idx += p;
                current_sum += bit_cnt[idx];
            }
            p >>= 1;
        }
        return idx + 1;
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // Step 1: Coordinate Compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        m = vals.size();

        bit_cnt.assign(m + 1, 0);
        bit_sum.assign(m + 1, 0);

        auto get_compressed_idx = [&](int val) {
            return lower_bound(vals.begin(), vals.end(), val) - vals.begin() + 1;
        };

        vector<long long> C(n - x + 1, 0);
        long long window_sum = 0;

        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            int idx = get_compressed_idx(v);
            add(idx, v);
            window_sum += v;

            // Maintain sliding window of size x
            if (i >= x) {
                int old_v = nums[i - x];
                int old_idx = get_compressed_idx(old_v);
                remove(old_idx, old_v);
                window_sum -= old_v;
            }

            if (i >= x - 1) {
                int target_cnt = (x + 1) / 2;
                int med_idx = find_kth(target_cnt);
                long long med_val = vals[med_idx - 1];

                auto [less_cnt, less_sum] = query(med_idx);
                int greater_cnt = x - less_cnt;
                long long greater_sum = window_sum - less_sum;

                // Total cost to convert all elements in window to med_val
                long long cost = (less_cnt * med_val - less_sum) + (greater_sum - greater_cnt * med_val);
                C[i - x + 1] = cost;
            }
        }

        long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j];
                
                if (i >= x) {
                    if (dp[i - x][j - 1] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + C[i - x]);
                    }
                }
            }
        }

        return dp[n][k];
    }
};
