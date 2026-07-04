class Solution {
public:
    int pos = 0;

    bool parseBoolExpr(string expression) {
        pos = 0;
        return parse(expression);
    }

private:
    bool parse(string &s) {
        char c = s[pos++];

        if (c == 't') return true;
        if (c == 'f') return false;

        if (c == '!') {
            pos++; 
            bool val = parse(s);
            pos++; 
            return !val;
        }

        
        pos++; 
        vector<bool> vals;
        vals.push_back(parse(s));
        while (s[pos] == ',') {
            pos++; 
            vals.push_back(parse(s));
        }
        pos++; 

        if (c == '&') {
            for (bool v : vals) if (!v) return false;
            return true;
        } else { 
            for (bool v : vals) if (v) return true;
            return false;
        }
    }
};
