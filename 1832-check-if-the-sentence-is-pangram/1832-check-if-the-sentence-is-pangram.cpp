class Solution {
public:
    bool checkIfPangram(string sen) {
        set<char> s(sen.begin(), sen.end());
        return s.size() == 26;
    }
};