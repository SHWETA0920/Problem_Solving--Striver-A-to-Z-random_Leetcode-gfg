class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0...i]
        vector<int> best(n, INF);

        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0;
        int ans = INF;
        int minLen = INF;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];

            // Need prefix[j] = prefix - target
            if (mp.count(prefix - target)) {
                int j = mp[prefix - target];
                int len = i - j;

                // A previous non-overlapping subarray exists
                if (j >= 0 && best[j] != INF) {
                    ans = min(ans, len + best[j]);
                }

                minLen = min(minLen, len);
            }

            // Best valid subarray ending at or before i
            best[i] = minLen;

            // Store latest prefix index
            mp[prefix] = i;
        }

        return ans == INF ? -1 : ans;
    }
};