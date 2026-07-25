class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int num=0;
         for(int i = n - 1; i >= 0; i--) {
            if (s[i] == 'I') {
                num += 1;
            } else if (s[i] == 'V') {
                if (i>0 && s[i-1] == 'I') {
                    num += 4;
                    i--;
                } else {
                    num += 5;
                }
            } else if (s[i] == 'X') {
                if (i>0 && s[i-1] == 'I') {
                    num += 9;
                    i--;
                } else {
                    num += 10;
                }
            } else if (s[i] == 'L') {
                if (i>0 && s[i-1] == 'X') {
                    num += 40;
                    i--;
                } else {
                    num += 50;
                }
            } else if (s[i] == 'C') {
                if (i>0 && s[i-1] == 'X') {
                    num += 90;
                    i--;
                } else {
                    num += 100;
                }
            } else if (s[i] == 'D') {
                if (i>0&& s[i-1] == 'C') {
                    num += 400;
                    i--;
                } else {
                    num += 500;
                }
            } else if (s[i] == 'M') {
                if (i>0 && s[i-1] == 'C') {
                    num += 900;
                    i--;
                } else {
                    num += 1000;
                }
            }
        }
        return num;
    
    }
};