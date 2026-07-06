class Solution {
public:
    int n;
    vector<vector<int>> dp;

    static bool myfun(string &w1, string &w2){
        return w1.length() < w2.length();
    }

    bool ispred(string &w1, string &w2){
        int m = w1.length();
        int nn = w2.length();

        if(nn - m != 1) return false;

        int i = 0, j = 0;

        while(i < m && j < nn){
            if(w1[i] == w2[j]) i++;
            j++;
        }

        return i == m;
    }

    int lis(vector<string>& words, int prev, int curr){
        if(curr == n) return 0;

        if(dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int taken = 0, not_taken = 0;

        if(prev == -1 || ispred(words[prev], words[curr])){
            taken = 1 + lis(words, curr, curr + 1);
        }

        not_taken = lis(words, prev, curr + 1);

        return dp[curr][prev + 1] = max(taken, not_taken);
    } 

    int longestStrChain(vector<string>& words) {
        n = words.size();

        sort(words.begin(), words.end(), myfun);

        dp.assign(n, vector<int>(n + 1, -1));

        return lis(words, -1, 0);
    }
};