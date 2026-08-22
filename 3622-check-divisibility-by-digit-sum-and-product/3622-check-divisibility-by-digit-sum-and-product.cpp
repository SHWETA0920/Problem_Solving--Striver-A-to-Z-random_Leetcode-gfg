class Solution {
public:
    int sum(int n) {
        int ans = 0;

        while (n > 0) {
            int rem = n % 10;
            ans += rem;
            n = n / 10;
        }

        return ans;
    }

    int product(int n) {
        int pro = 1;

        while (n > 0) {
            int rem = n % 10;
            pro *= rem;
            n = n / 10;
        }

        return pro;
    }

    bool checkDivisibility(int n) {
        int s = sum(n);
        int p = product(n);

        return n % (s + p) == 0;
    }
};