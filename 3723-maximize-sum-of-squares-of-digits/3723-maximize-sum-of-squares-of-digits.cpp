class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";

        if (sum > 9 * num) return res;

        while (sum >= 9) {
            res += '9';
            sum -= 9;
        }

        if (sum > 0) {
            res += to_string(sum);
        }

        while (res.size() < num) {
            res += '0';
        }

        return res;
    }
};