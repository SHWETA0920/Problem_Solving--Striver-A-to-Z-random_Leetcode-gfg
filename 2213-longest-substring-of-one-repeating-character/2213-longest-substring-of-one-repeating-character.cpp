class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best;
        int len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Initially
        res.prefix = a.prefix;
        res.suffix = b.suffix;

        // Entire LEFT segment has same character
        if (a.prefix == a.len && a.leftChar == b.leftChar) {
            res.prefix = a.len + b.prefix;
        }

        // Entire RIGHT segment has same character
        if (b.suffix == b.len && a.rightChar == b.rightChar) {
            res.suffix = b.len + a.suffix;
        }

        // Best answer is either completely inside left/right
        res.best = max(a.best, b.best);

        // Or it crosses the boundary
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
        }

        return res;
    }

    void build(int idx, int l, int r, string &s) {

        if (l == r) {
            tree[idx].leftChar = s[l];
            tree[idx].rightChar = s[l];

            tree[idx].prefix = 1;
            tree[idx].suffix = 1;
            tree[idx].best = 1;
            tree[idx].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {

        if (l == r) {
            tree[idx].leftChar = ch;
            tree[idx].rightChar = ch;

            tree[idx].prefix = 1;
            tree[idx].suffix = 1;
            tree[idx].best = 1;
            tree[idx].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * idx, l, mid, pos, ch);
        }
        else {
            update(2 * idx + 1, mid + 1, r, pos, ch);
        }

        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, index, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};