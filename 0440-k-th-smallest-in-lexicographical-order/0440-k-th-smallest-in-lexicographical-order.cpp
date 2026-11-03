class Solution {
public:
    long long Count(long long curr, long long next, long long n) {
        long long countNum = 0;
        while (curr <= n) {
            countNum += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return countNum;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;
        k -= 1;

        while (k > 0) {
            long long count = Count(curr, curr + 1, n);
            if (count <= k) {
                curr++;
                k -= count;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};
