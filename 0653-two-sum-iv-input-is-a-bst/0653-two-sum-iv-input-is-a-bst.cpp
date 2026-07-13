class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int, int>& m) {
        if (!root)
            return;
        m[root->val]++;
        if (root->left)
            dfs(root->left, m);
        if (root->right)
            dfs(root->right, m);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        dfs(root, mp);

        for (auto it : mp) {
            int val = it.first;
            int rem = k - val;

            if (rem == val) {
                if (it.second > 1)
                    return true;
            } else {
                if (mp.find(rem) != mp.end())
                    return true;
            }
        }
        return false;
    }
};