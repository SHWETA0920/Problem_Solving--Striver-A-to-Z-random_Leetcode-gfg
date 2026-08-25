class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string curr = "";
        int num = 0;

        for (char ch : s) {

            // Build the number
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // Start of a new nested string
            else if (ch == '[') {
                nums.push(num);
                strs.push(curr);

                num = 0;
                curr = "";
            }

            // Normal character
            else if (isalpha(ch)) {
                curr += ch;
            }

            // End of current nested string
            else if (ch == ']') {
                int repeat = nums.top();
                nums.pop();

                string previous = strs.top();
                strs.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += curr;
                }

                curr = previous + temp;
            }
        }

        return curr;
    }
};