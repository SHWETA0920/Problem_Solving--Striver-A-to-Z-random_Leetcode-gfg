class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int first = 1; first <= 9; first++) {
            if (freq[first] == 0) continue;

            freq[first]--;

            for (int second = 0; second <= 9; second++) {
                if (freq[second] == 0) continue;

                freq[second]--;

                for (int last = 0; last <= 8; last += 2) {
                    if (freq[last] > 0) {
                        ans++;
                    }
                }

                freq[second]++;
            }

            freq[first]++;
        }

        return ans;
    }
};