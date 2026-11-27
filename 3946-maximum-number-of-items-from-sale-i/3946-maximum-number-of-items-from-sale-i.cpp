class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        vector<int> freeCount(n, 0);

        for (int i = 0; i < n; ++i) {
            int fi = items[i][0];
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % fi == 0) {
                    ++freeCount[i];
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        // 1. 0/1 knapsack for the first copy of each item (unlocks free copies)
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int gain = 1 + freeCount[i];
            for (int c = budget; c >= price; --c) {
                dp[c] = max(dp[c], dp[c - price] + gain);
            }
        }

        // 2. Unbounded knapsack for extra copies of any item (+1 item each)
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            for (int c = price; c <= budget; ++c) {
                dp[c] = max(dp[c], dp[c - price] + 1);
            }
        }

        return dp[budget];
    }
};