class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> suf(n+1, 0);
        int j = m - 1;

        for(int i = n - 1; i >= 0; i--){
            if(j >= 0 && word1[i] == word2[j]){
                j--;
            }
            suf[i] = m - 1 - j;
        }

        vector<int> ans;
        int i = 0, k = 0;
        bool used = false;

        while(i < n && k < m){
            if(word1[i] == word2[k]){
                ans.push_back(i);
                i++; k++;
            }
            else{
                // 🔥 KEY FIX: prefer skipping
                if(!used && suf[i+1] >= m - (k+1)){
                    // take mismatch ONLY if needed
                    ans.push_back(i);
                    used = true;
                    i++; k++;
                }
                else{
                    i++;
                }
            }
        }

        if(k < m) return {};
        return ans;
    }
};