class Solution {
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int k;
    vector<Node> seg;

    Node merge(const Node& left, const Node& right) {
        Node res;

        res.prod = (left.prod * right.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] = left.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int rem = (left.prod * r) % k;
            res.cnt[rem] += right.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int rem = nums[l] % k;
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            value %= k;

            seg[node].prod = value;

            memset(seg[node].cnt, 0, sizeof(seg[node].cnt));
            seg[node].cnt[value] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        if (r < ql || l > qr) {
            Node res;
            res.prod = 1 % k;
            return res;
        }

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums,
                             int k,
                             vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        for (int& x : nums) {
            x %= k;
        }

        for (auto& q : queries) {
            q[1] %= k;
        }

        seg.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};
