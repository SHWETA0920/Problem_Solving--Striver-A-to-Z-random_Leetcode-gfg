class Solution {
public:
    bool isPalindrome(int n) {
        if (n < 0) return false;

        int num = 0;
        int a = n;

        while (a > 0) {
            int rem = a % 10;

            if (num > INT_MAX / 10) return false;

            num = num * 10 + rem;
            a = a / 10;
        }

        return n == num;
    }
};