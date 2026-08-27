class Solution {
public:
    void dfs(TreeNode* root, int dir, int len, int &ans) {
        if (root == NULL) return;

        ans = max(ans, len);

        if (dir == 0) {
            // Previous move was LEFT, so next should be RIGHT
            if (root->right)
                dfs(root->right, 1, len + 1, ans);

            // Start a new ZigZag from left
            if (root->left)
                dfs(root->left, 0, 1, ans);
        }
        else {
            // Previous move was RIGHT, so next should be LEFT
            if (root->left)
                dfs(root->left, 0, len + 1, ans);

            // Start a new ZigZag from right
            if (root->right)
                dfs(root->right, 1, 1, ans);
        }
    }

    int longestZigZag(TreeNode* root) {
        if (root == NULL) return 0;

        int ans = 0;

        // Try starting in both directions
        dfs(root->left, 0, 1, ans);
        dfs(root->right, 1, 1, ans);

        return ans;
    }
};